/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:48:20 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/11 18:28:19 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*path(char *command, char **env)
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

void	first_child(char **av, char **env, int *pipe_fd, int *file_fd)
{
	pid_t	pid;
	char	**command1;

	pid = fork();
	if (pid < 0)
		ft_error(3, NULL, NULL);
	else if (pid == 0)
	{
		file_fd[0] = open(av[1], O_RDONLY);
		if (file_fd[0] < 0)
			ft_error(4, av[1], NULL);
		command1 = ft_split(av[2], ' ');
		if (command1 == NULL)
			ft_error(5, NULL, NULL);
		close(pipe_fd[0]);
		dup2(file_fd[0], 0);
		dup2(pipe_fd[1], 1);
		close(file_fd[0]);
		close(pipe_fd[1]);
		if (command1[0] != NULL && ft_strchr(command1[0], '/') != NULL)
			execve(command1[0], command1, env);
		else if (command1[0] != NULL && path(command1[0], env) != NULL)
			execve(path(command1[0], env), command1, env);
		command_error(command1);
	}
}

void	second_child(char **av, char **env, int *pipe_fd, int *file_fd)
{
	pid_t	pid;
	char	**command2;

	pid = fork();
	if (pid < 0)
		ft_error(3, NULL, NULL);
	else if (pid == 0)
	{
		file_fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file_fd[1] < 0)
			ft_error(6, av[4], NULL);
		command2 = ft_split(av[3], ' ');
		if (command2 == NULL)
			ft_error(5, NULL, NULL);
		close(pipe_fd[1]);
		dup2(file_fd[1], 1);
		dup2(pipe_fd[0], 0);
		close(file_fd[1]);
		close(pipe_fd[0]);
		if (command2[0] != NULL && ft_strchr(command2[0], '/') != NULL)
			execve(command2[0], command2, env);
		else if (command2[0] != NULL && path(command2[0], env) != NULL)
			execve(path(command2[0], env), command2, env);
		command_error(command2);
	}
}

int	main(int ac, char **av, char **env)
{
	int	pipe_fd[2];
	int	file_fd[2];
	int	status;

	if (ac != 5)
		ft_error(1, NULL, NULL);
	if (pipe(pipe_fd) < 0)
		ft_error(2, NULL, NULL);
	first_child(av, env, pipe_fd, file_fd);
	second_child(av, env, pipe_fd, file_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
