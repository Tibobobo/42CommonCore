/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:23:55 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/15 22:13:39 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_paths(t_sh *sh, char *temp, char **paths, char *file)
{
	temp = getenv("PATH");
	if (temp == NULL)
		command_error(sh, file, 2);
	paths = ft_split(temp, ':');
	if (paths == NULL)
		ft_error(sh, 1);
	return (paths);
}

char	*get_path(t_sh *sh, char *file, char **env)
{
	char	**paths;
	char	*temp;
	char	*path_try;
	int		i;

	(void)env;
	temp = NULL;
	paths = NULL;
	paths = split_paths(sh, temp, paths, file);
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

void	exec_command_2(t_comm *cmd, t_sh *sh, char **env)
{
	char	*path;

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

void	exec_command(t_comm *cmd, t_sh *sh, int *pipe_fd, char **env)
{
	if (cmd->file == NULL || cmd->file[0] == '\0')
		return ;
	cmd->pid = fork();
	if (cmd->pid < 0)
		ft_error(sh, 5);
	else if (cmd->pid == 0)
	{
		if (pipe_fd != NULL)
		{
			close(pipe_fd[0]);
			if (dup2(pipe_fd[1], 1) < 0)
				ft_error(sh, 3);
			close(pipe_fd[1]);
		}
		exec_command_2(cmd, sh, env);
	}
	else if (cmd->pid != 0 && pipe_fd != NULL)
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], 0) < 0)
			ft_error(sh, 3);
		close(pipe_fd[0]);
	}
	else
		close(0);
}

void	execution(t_sh *sh, char **env)
{
	t_comm	*cmd;
	int		pipe_fd[2];

	cmd = sh->comm;
	while (cmd != NULL)
	{
		if ((cmd->infile == 1 || cmd->outfile == 1)
			&& redirections(cmd, sh) != 0)
		{
			cmd = cmd->next;
			continue ;
		}
		if (cmd->outfile == 0 && cmd->next != NULL)
		{
			if (pipe(pipe_fd) < 0)
				ft_error(sh, 4);
			exec_command(cmd, sh, pipe_fd, env);
		}
		else
			exec_command(cmd, sh, NULL, env);
		cmd = cmd->next;
	}
	wait_for_children(sh);
}
