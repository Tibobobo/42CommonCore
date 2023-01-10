/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:48:20 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/10 13:41:36 by tgrasset         ###   ########.fr       */
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
		ft_error(5, NULL);
	return (paths);
}

char	*path(char *command, char **env)
{
	char	**paths;
	char	*temp;
	char	*path_try;
	int		i;

	paths = split_paths(env);
	i = 0;
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		if (temp == NULL)
			ft_error(5, NULL);
		path_try = ft_strjoin(temp, command);
		free(temp);
		if (path_try == NULL)
			ft_error(5, NULL);
		if (access(path_try, F_OK) == 0)
			return (free_split(paths), path_try);
		free(path_try);
		i++;
	}
	free_split(paths);
	return (free_split(paths), NULL);
}

void	first_child(char **av, char **env, int *pipe_fd, int *file_fd)
{
	pid_t	pid;
	char	**command1;

	pid = fork();
	if (pid < 0)
		ft_error(3, NULL);
	else if (pid == 0)
	{
		file_fd[0] = open(av[1], O_RDONLY);
		if (file_fd[0] < 0)
			ft_error(4, av[1]);
		command1 = ft_split(av[2], ' ');
		if (command1 == NULL)
			ft_error(5, NULL);
		close(pipe_fd[0]);
		dup2(file_fd[0], 0);
		dup2(pipe_fd[1], 1);
		if (command1[0] != NULL && path(command1[0], env) != NULL)
		{
			execve(path(command1[0], env), command1, env);
			free_split(command1);
		}
		else
			command_error(command1);
	}
}

void	second_child(char **av, char **env, int *pipe_fd, int *file_fd)
{
	pid_t	pid;
	char	**command2;

	pid = fork();
	if (pid < 0)
		ft_error(3, NULL);
	else if (pid == 0)
	{
		file_fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file_fd[1] < 0)
			ft_error(6, av[4]);
		command2 = ft_split(av[3], ' ');
		if (command2 == NULL)
			ft_error(5, NULL);
		close(pipe_fd[1]);
		dup2(file_fd[1], 1);
		dup2(pipe_fd[0], 0);
		if (command2[0] != NULL && path(command2[0], env) != NULL)
		{
			execve(path(command2[0], env), command2, env);
			free_split(command2);
		}
		else
			command_error(command2);
	}
}

int	main(int ac, char **av, char **env)
{
	int	pipe_fd[2];
	int	file_fd[2];
	int	status;

	if (ac != 5)
		ft_error(1, NULL);
	if (pipe(pipe_fd) < 0)
		ft_error(2, NULL);
	first_child(av, env, pipe_fd, file_fd);
	second_child(av, env, pipe_fd, file_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
