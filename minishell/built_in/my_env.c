/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:54:24 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/27 16:56:59 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	my_env(t_sh *sh, t_comm *cmd, char **env)
{
	int	i;

	if (cmd->argv[1] != NULL)
	{
		ft_putendl_fd("msh: env: only works without arguments", 2);
		free_all(sh);
		exit (1);
	}
	i = 0;
	while (env[i] != NULL)
	{
		ft_putendl_fd(env[i], 1);
		i++;
	}
	free_all(sh);
	exit (0);
}
