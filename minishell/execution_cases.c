/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:10:03 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/17 14:12:57 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_in_pipe(t_sh *sh, int *pipe_fd, t_comm *cmd, char **env)
{
	if (pipe(pipe_fd) < 0)
		ft_error(sh, 4);
	exec_command(cmd, sh, pipe_fd, env);
}

void	pipe_0(t_sh *sh, int	*pipe_fd, t_comm *cmd)
{
	if (pipe(pipe_fd) < 0)
		ft_error(sh, 4);
	cmd->pid = fork();
	if (cmd->pid < 0)
		ft_error(sh, 5);
	else if (cmd->pid == 0)
	{
		close(cmd->stdout_save);
		close(sh->stdin_save);
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], 1) < 0)
			ft_error(sh, 3);
		close(pipe_fd[1]);
		write(1, "", 0);
		exit(0);
	}
	else if (cmd->pid != 0)
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], 0) < 0)
			ft_error(sh, 3);
		close(pipe_fd[0]);
	}
}

void	exec_outfile_pipe_0(t_sh *sh, int *pipe_fd, t_comm *cmd, char **env)
{
	if (cmd->file == NULL || cmd->file[0] == '\0')
		return ;
	cmd->pid = fork();
	if (cmd->pid < 0)
		ft_error(sh, 5);
	else if (cmd->pid == 0)
		exec_command_2(cmd, sh, env);
	else
		pipe_0(sh, pipe_fd, cmd);
}
