/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:23:55 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/14 19:50:02 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    command_error(t_sh *sh, char *cmd, int num)
{
	if (num == 1)
	{
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Permission denied", 2);
		free_all(sh);
		exit (126);
	}
	else if (num == 2)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
		free_all(sh);
		exit (127);
	}
}

char    *get_path(t_sh *sh, char *file, char **env)
{
	char    **paths;
	char    *temp;
	char    *path_try;
	int     i;

	(void)env;
	temp = getenv("PATH");
	if (temp == NULL)
		command_error(sh, file, 2);
	paths = ft_split(temp, ':');
	if (paths == NULL)
		ft_error(sh, 1);
	i = 0;
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		if (temp == NULL)
			ft_error(sh, 1);
		path_try = ft_strjoin(temp, file);
		free(temp);
		if (path_try == NULL)
			ft_error(sh, 1);
		if (access(path_try, F_OK) == 0)
			return (free_lex(paths), path_try);
		free(path_try);
		i++;
	}
	return (free_lex(paths), NULL);
}

void    exec_command_2(t_comm *cmd, t_sh *sh, char **env)
{
	char    *path;

	if (ft_strchr(cmd->file, '/') != NULL)
		path = cmd->file;
	else
		path = get_path(sh, cmd->file, env);
	if (path != NULL && access(path, X_OK) == 0)
		execve(path, cmd->argv, env);
	else if (path != NULL && access(path, F_OK) == 0)
	{
		free(path);
		command_error(sh, cmd->file, 1);
	}
	else
		command_error(sh, cmd->file, 2);
}

void    exec_command(t_comm *cmd, t_sh *sh, int *pipe_fd, char **env)
{
	cmd->pid = fork();
	if (cmd->pid < 0)
		ft_error(sh, 5);                    //mieux proteger
	else if (cmd->pid == 0)
	{
		if (pipe_fd != NULL)
		{
			close(pipe_fd[0]);
			if (dup2(pipe_fd[1], 1) < 0)
				ft_error(sh, 3);            //mieux proteger
			close(pipe_fd[1]);
		}
		exec_command_2(cmd, sh, env);
	}
	else if (cmd->pid != 0 && pipe_fd != NULL)
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], 0) < 0)
			ft_error(sh, 3);                //mieux proteger
		close(pipe_fd[0]);
	}
}

void    execution(t_sh *sh, char **env)
{
	t_comm  *cmd;
	int pipe_fd[2];

	cmd = sh->comm;
	while (cmd != NULL)
	{
		if (cmd->infile == 1 || cmd->outfile == 1)
			if (redirections(cmd, sh) != 0)
			{
				cmd = cmd->next;
				continue ;
			}
		if (cmd->outfile == 0 && cmd->next != NULL)
		{
			if (pipe(pipe_fd) < 0)
				ft_error(sh, 4);            //mieux proteger
			exec_command(cmd, sh, pipe_fd, env);
		}
		else
			exec_command(cmd, sh, NULL, env);
		cmd = cmd->next;
	}
	// wait_for_children(sh);
}
