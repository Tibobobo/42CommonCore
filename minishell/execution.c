/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:23:55 by tgrasset          #+#    #+#             */
/*   Updated: 2023/03/01 10:26:08 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	close(cmd->stdout_save);
	close(sh->stdin_save);
	if (cmd->file != NULL && cmd->file[0] == '\0')
		command_error(sh, cmd->file, 2, NULL);
	check_built_in(sh, cmd, env, 1);
	if (ft_strchr(cmd->file, '/') != NULL)
	{
		path = ft_strdup(cmd->file);
		if (path == NULL)
			ft_error(sh, 1);
	}
	else
		path = get_path(sh, cmd->file, env);
	if (path != NULL && access(path, X_OK) == 0)
	{
		execve(path, cmd->argv, env);
		command_error(sh, cmd->file, 3, path);
	}
	else if (path != NULL && access(path, F_OK) == 0)
		command_error(sh, cmd->file, 1, path);
	else
		command_error(sh, cmd->file, 2, path);
}

void	exec_command(t_comm *cmd, t_sh *sh, int *pipe_fd, char **env)
{
	if (cmd->file == NULL)
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

void	choose_exec_case(t_sh *sh, t_comm *cmd, int *pipe_fd, char **env)
{
	if (cmd->next == NULL && env_built_in(cmd) == 0)
	{
		check_built_in(sh, cmd, env, 0);
		return ;
	}
	else if (cmd->outfile == 1 && cmd->next != NULL)
		exec_outfile_pipe_0(sh, pipe_fd, cmd, env);
	else if (cmd->outfile == 0 && cmd->next != NULL)
		exec_in_pipe(sh, pipe_fd, cmd, env);
	else
		exec_command(cmd, sh, NULL, env);
	close(1);
	if (dup2(cmd->stdout_save, 1) < 0)
		ft_error(sh, 3);
	close(cmd->stdout_save);
}

void	execution(t_sh *sh, char **env)
{
	t_comm	*cmd;
	int		pipe_fd[2];

	cmd = sh->comm;
	while (cmd != NULL)
	{
		if (!(cmd->next == NULL && env_built_in(cmd) == 0))
		{
			cmd->stdout_save = dup(1);
			if (cmd->stdout_save < 0)
				ft_error(sh, 3);
		}
		if (redirections(cmd, sh) != 0 || cmd->file == NULL
			|| (cmd->outfile == 0 && cmd->next != NULL
				&& cmd->next->infile == 1))
		{
			if (cmd->next != NULL)
				pipe_0(sh, pipe_fd, cmd);
			close(cmd->stdout_save);
		}
		else
			choose_exec_case(sh, cmd, pipe_fd, env);
		cmd = cmd->next;
	}
}
