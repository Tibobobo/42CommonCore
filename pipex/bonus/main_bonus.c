/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:25:30 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/11 14:20:57 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**split_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == NULL)
		i++;
	paths = ft_split(env[i] + 5, ':');
	if (paths == NULL)
		ft_error(5, NULL, NULL);
	return (paths);
}

char	*get_path(char *command, char **env)
{
	char	**paths;
	char	*temp;
	char	*path_try;
	int		i;

	paths = split_paths(env);
	if (paths == NULL)
		ft_error(5, NULL, NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		if (temp == NULL)
			ft_error(5, NULL, paths);
		path_try = ft_strjoin(temp, command);
		free(temp);
		if (path_try == NULL)
			ft_error(5, NULL, paths);
		if (access(path_try, F_OK | X_OK) == 0)
			return (free_split(paths), path_try);
		free(path_try);
		i++;
	}
	return (free_split(paths), NULL);
}

void    exec(char *command, char **env)
{
    char    **args;
    char    *path;

    args = ft_split(command, ' ');
    if (args == NULL)
        ft_error(4, NULL, NULL);
    if (ft_strchr(command, '/') != NULL)
        path = args[0];
    else
        path = get_path(args[0], env);
    if (path != NULL)
        execve(path, args, env);
    command_error(args);
}

void    redirect(char *command, int fdin, char **env)
{
    pid_t   pid;
    int     pipe_fd[2];

    if (pipe(pipe_fd) < 0)
        ft_error(2, NULL, NULL);
    pid = fork();
    if (pid < 0)
        ft_error(3, NULL, NULL);
    else if (pid == 0)
    {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], 1);
        if (fdin == 0)
            exit (1);
        else
            exec(command, env);
    }
    else
    {
        close(pipe_fd[1]);
        dup2(pipe_fd[0], 0);
        waitpid(pid, NULL, 0);
    }
}

int get_fd(char *file, int in_out)
{
    if (in_out == 0)
    {
        if (access(file, F_OK) != 0)
        {
            ft_putstr_fd("pipex: no such file or directory: ", 2);
            ft_putendl_fd(file, 2);
            return (0);
        }
        return (open(file, O_RDONLY));
    }
    else
        return (open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644));
}

int main(int ac, char **av, char **env)
{
    int fdin;
    int fdout;
    int i;

    if (ac < 5)
        ft_error(1, NULL, NULL);
    fdin = get_fd(av[1], 0);
    fdout = get_fd(av[ac - 1], 1);
    i = 3;
    dup2(fdin, 0);
    dup2(fdout, 1);
    redirect(av[2], fdin, env);
    while (i < ac - 2)
    {
        redirect(av[i], 1, env);
        i++;
    }
    exec(av[i], env);
    return (0);
}
