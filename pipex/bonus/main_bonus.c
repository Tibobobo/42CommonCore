/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:25:30 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/13 14:20:07 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec(char *command, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(command, ' ');
	if (args == NULL)
		ft_error(4, NULL, NULL);
	if (ft_strchr(command, '/') != NULL)
		path = args[0];
	else
		path = get_path(args, env);
	if (path != NULL && access(path, X_OK) == 0)
		execve(path, args, env);
	else if (path != NULL && access(path, F_OK) == 0)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putendl_fd(args[0], 2);
		if (ft_strncmp(path, args[0], ft_strlen(path) + 1) != 0)
			free(path);
		free_split(args);
		exit (126);
	}
	command_error(args);
}

void	childsplay(int	*pipe_fd)
{
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], 0) < 0)
		ft_error(6, NULL, NULL);
	close(pipe_fd[0]);
}

void	redirect(char *command, int fdin, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		ft_error(2, NULL, NULL);
	pid = fork();
	if (pid < 0)
		ft_error(3, NULL, NULL);
	else if (pid == 0)
		childsplay(pipe_fd);
	else
	{
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], 1) < 0)
			ft_error(6, NULL, NULL);
		close(pipe_fd[1]);
		if (fdin == 0)
			exit (1);
		else
			exec(command, env);
	}
}

int	get_fd(char *file, int in_out)
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

int	main(int ac, char **av, char **env)
{
	int	fdin;
	int	fdout;
	int	i;

	i = 2;
	if (ac < 5)
		ft_error(1, NULL, NULL);
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && av[1][8] == '\0')
		return (here_doc(ac, av, env, 0), 0);
	fdin = get_fd(av[1], 0);
	fdout = get_fd(av[ac - 1], 1);
	fds_check_and_dup(&fdin, &fdout);
	redirect(av[2], fdin, env);
	while (++i < ac - 2)
		redirect(av[i], 1, env);
	exec(av[i], env);
	return (0);
}
