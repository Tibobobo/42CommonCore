/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:16:48 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/12 10:58:01 by tgrasset         ###   ########.fr       */
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

int	ft_error(int num, char *arg, char **split)
{
	if (split != NULL)
		free_split(split);
	if (num == 1)
		ft_putstr_fd("Error\nUsage: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 2);
	else if (num == 2)
		ft_putstr_fd("Pipe error\n", 2);
	else if (num == 3)
		ft_putstr_fd("Fork error\n", 2);
	else if (num == 4)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(arg, 2);
	}
	else if (num == 5)
		ft_putstr_fd("Malloc error\n", 2);
	else if (num == 6)
	{
		ft_putstr_fd("Error while creating or writing to file: ", 2);
		ft_putendl_fd(arg, 2);
	}
	else if (num == 7)
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
