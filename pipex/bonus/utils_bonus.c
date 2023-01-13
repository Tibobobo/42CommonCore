/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:25:43 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/13 10:54:02 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_path(char **args, char **env)
{
	char	**paths;
	char	*temp;
	char	*path_try;
	int		i;

	paths = split_paths(args, env);
	if (paths == NULL)
		ft_error(4, args, NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		if (temp == NULL)
			ft_error(4, paths, args);
		path_try = ft_strjoin(temp, args[0]);
		free(temp);
		if (path_try == NULL)
			ft_error(4, paths, args);
		if (access(path_try, F_OK) == 0)
			return (free_split(paths), path_try);
		free(path_try);
		i++;
	}
	return (free_split(paths), NULL);
}

char	**split_paths(char **args, char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i] != NULL && ft_strnstr(env[i], "PATH=", 5) == NULL)
		i++;
	if (env[i] == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(args[0], 2);
		free_split(args);
		exit(127);
	}
	paths = ft_split(env[i] + 5, ':');
	if (paths == NULL)
		ft_error(4, args, NULL);
	return (paths);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_error(int num, char **split, char **split2)
{
	if (split != NULL)
		free_split(split);
	if (split2 != NULL)
		free_split(split2);
	if (num == 1)
		ft_putstr_fd("Usage: ./pipex [file1] [cmd1] ... [cmdn] [file2]\n", 2);
	else if (num == 2)
		ft_putstr_fd("Pipe error\n", 2);
	else if (num == 3)
		ft_putstr_fd("Fork error\n", 2);
	else if (num == 4)
		ft_putstr_fd("Malloc error\n", 2);
	else if (num == 5)
		ft_putstr_fd("Error while opening or creating file: ", 2);
	else if (num == 6)
		ft_putstr_fd("Dup2 error\n", 2);
	exit(1);
}

int	command_error(char **command)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(command[0], 2);
	free_split(command);
	exit(127);
}
