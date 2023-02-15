/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:49:07 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/15 21:10:31 by tgrasset         ###   ########.fr       */
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

void	command_error(t_sh *sh, char *cmd, int num)
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
