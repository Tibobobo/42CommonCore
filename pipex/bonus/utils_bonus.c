/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:25:43 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/12 09:51:06 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_path(char *command, char **env)
{
	char	**paths;
	char	*temp;
	char	*path_try;
	int		i;

	paths = split_paths(env);
	if (paths == NULL)
		ft_error(4, NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		if (temp == NULL)
			ft_error(4, paths);
		path_try = ft_strjoin(temp, command);
		free(temp);
		if (path_try == NULL)
			ft_error(4, paths);
		if (access(path_try, F_OK | X_OK) == 0)
			return (free_split(paths), path_try);
		free(path_try);
		i++;
	}
	return (free_split(paths), NULL);
}

char	**split_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == NULL)
		i++;
	paths = ft_split(env[i] + 5, ':');
	if (paths == NULL)
		ft_error(4, NULL);
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

int	ft_error(int num, char **split)
{
	if (split != NULL)
		free_split(split);
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
