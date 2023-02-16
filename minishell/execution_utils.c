/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:49:07 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/16 11:42:30 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_for_children(t_sh *sh)
{
	t_comm	*tmp;

	tmp = sh->comm;
	while (tmp != NULL)
	{
		if (tmp->file != NULL && tmp->file[0] != '\0')
			waitpid(tmp->pid, NULL, 0);
		tmp = tmp->next;
	}
}

char	**split_paths(t_sh *sh, char *temp, char **paths, char *file)
{
	temp = getenv("PATH");
	if (temp == NULL)
		command_error(sh, file, 2, NULL);
	paths = ft_split(temp, ':');
	if (paths == NULL)
		ft_error(sh, 1);
	return (paths);
}

void	check_if_dir(t_sh *sh, char *path, char *cmd)
{
	struct stat	buf;

	if (stat(path, &buf) < 0)
		ft_error(sh, 6);
	if (S_ISDIR(buf.st_mode))
	{
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": Is a directory", 2);
		free_all(sh);
		if (path != NULL)
			free(path);
		exit (126);
	}
	ft_putstr_fd("msh: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": Execve failed", 2);
	if (path != NULL)
		free(path);
	free_all(sh);
	exit (126);
}

void	check_no_such_file(t_sh *sh, char *path, char *cmd)
{
	if (ft_strchr(cmd, '/') == NULL)
		return ;
	ft_putstr_fd("msh: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": No such file or directory", 2);
	if (path != NULL)
		free(path);
	free_all(sh);
	exit (127);
}

void	command_error(t_sh *sh, char *cmd, int num, char *path)
{
	if (num == 1)
	{
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Permission denied", 2);
		if (path != NULL)
			free(path);
		free_all(sh);
		exit (126);
	}
	else if (num == 2)
	{
		check_no_such_file(sh, path, cmd);
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
		if (path != NULL)
			free(path);
		free_all(sh);
		exit (127);
	}
	check_if_dir(sh, path, cmd);
}
