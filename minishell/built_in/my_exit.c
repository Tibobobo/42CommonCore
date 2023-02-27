/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:30:44 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/27 16:56:21 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_ret_val;

void	my_exit(t_sh *sh, t_comm *cmd, int forked)
{
	if (cmd->argv[1] != NULL)
	{
		if (forked == 1)
		{
			ft_putendl_fd("msh: exit: only works without arguments", 2);
			free_all(sh);
			exit (1);
		}
		ft_putendl_fd("msh: exit: only works without arguments", 2);
		g_ret_val = 1;
	}
	else
	{
		free_all(sh);
		if (forked == 0)
		{
			printf("exit\n");
			close (sh->stdin_save);
			rl_clear_history();
		}
		exit (0);
	}
}
