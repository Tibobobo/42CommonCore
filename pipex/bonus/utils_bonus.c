/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:25:43 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/11 11:24:11 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		ft_putstr_fd("Usage: ./pipex [file1] [cmd1] ... [cmdn] [file2]\n", 2);
	else if (num == 2)
		ft_putstr_fd("Pipe error\n", 2);
	else if (num == 3)
		ft_putstr_fd("Fork error\n", 2);
	else if (num == 4)
		ft_putstr_fd("Malloc error\n", 2);
	else if (num == 5)
	{
		ft_putstr_fd("Error while creating or writing to file: ", 2);
		ft_putendl_fd(arg, 2);
	}
	else if (num == 6)
		ft_putstr_fd("Execve error\n", 2);
	exit(1);
}

int	command_error(char **command)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(command[0], 2);
	free_split(command);
	exit(127);
}

