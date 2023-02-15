/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:55:35 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/15 14:24:01 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_last_redir(t_redir *redir)
{
	t_redir	*temp;

	temp = redir->next;
	while (temp != NULL)
	{
		if (temp->output == redir->output)
			return (0);
		temp = temp->next;
	}
	return (1);
}

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

void	output_file_create(t_sh *sh, t_redir *redir)
{
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
}

void	here_doc(t_redir *redir)
{
	char *line;
	
	while (1)
	{
		line = readline(">");
		if (line != NULL && ft_strncmp(line, redir->name, ft_strlen(redir->name + 1)) == 0)
		{
			free(line);
			break ;
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
		else if (redir->doubl == 1 && redir->output == 0)       //here_doc a lancer meme si un input file est faux avant
		    here_doc(redir);
		else
			output_file_create(sh, redir);
		redir = redir->next;
	} 
	return (0);
}
