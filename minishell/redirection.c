/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:55:35 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/15 20:42:23 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input_file_check(t_sh *sh, t_redir *redir)
{
	if (access(redir->name, F_OK) != 0)
	{
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(redir->name, 2);
		ft_putendl_fd(": No such file or directory", 2);  // $? = 1
		return (1);
	}
	else if (access(redir->name, R_OK) != 0)
	{
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(redir->name, 2);
		ft_putendl_fd(": Permission denied", 2);          // $? = 1
		return (1);
	}
	if (is_last_redir(redir))
	{
		redir->fd = open(redir->name, O_RDONLY);
		if (redir->fd < 0)
			ft_error(sh, 2);
		if (dup2(redir->fd, 0) < 0)
			ft_error(sh, 3);
		close(redir->fd);
	}
	return (0);
}

int	output_file_create(t_sh *sh, t_redir *redir)
{
	if (check_if_empty_str(redir->name) != 0)			// $? = 1
		return (1);
	if (redir->doubl == 0)
	{
		redir->fd = open(redir->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (redir->fd < 0)
			ft_error(sh, 2);
	}
	else
	{
		redir->fd = open(redir->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (redir->fd < 0)
			ft_error(sh, 2);
	}
	if (is_last_redir(redir))
	{
		if (dup2(redir->fd, 1) < 0)
			ft_error(sh, 3);
		close(redir->fd);
	}
	return (0);
}

void	here_doc(t_sh *sh, t_redir *redir)
{
	char	*line;
	pid_t	pid;

	line = NULL;
	if (is_last_redir(redir))
	{
		pid = fork();
		if (pid < 0)
			ft_error(sh, 4);
		if (pid != 0)
		{
			waitpid(pid, NULL, 0);
			return ;
		}
	}
	while (1)
	{
		line = readline(">");
		if (line != NULL
			&& ft_strncmp(line, redir->name, ft_strlen(redir->name + 1)) == 0)
		{
			free(line);
			exit (0);
		}
		if (is_last_redir(redir))
			ft_putstr_fd(line, 1);
		free(line);
	}
}

int	redirections(t_comm *cmd, t_sh *sh)
{
	t_redir	*redir;

	if (cmd->redir == NULL)
		return (0);
	redir = cmd->redir;
	while (redir != NULL)
	{
		if (redir->doubl == 0 && redir->output == 0)
		{
			if (input_file_check(sh, redir) != 0)
			{
				close_fds(cmd);
				return (1);
			}
		}
		else if (redir->doubl == 1 && redir->output == 0)
			here_doc(sh, redir);
		else if (output_file_create(sh, redir) != 0)
		{
			close_fds(cmd);
			return (1);
		}
		redir = redir->next;
	}
	return (0);
}
