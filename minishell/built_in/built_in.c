/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:39:32 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/27 16:03:47 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_built_in(t_sh *sh, t_comm *cmd, char **env, int forked)
{
	if (ft_strncmp(cmd->file, "echo", 5) == 0)
		my_echo(sh, cmd);
	else if (ft_strncmp(cmd->file, "cd", 3) == 0)
		my_cd(sh, cmd, env, forked);//env ? peut etre pour modif PWD et OLDPWD
	else if (ft_strncmp(cmd->file, "pwd", 4) == 0)
		my_pwd();
	// else if (ft_strncmp(cmd->file, "export", 7) == 0)
	//     my_export(sh, cmd, env);
	// else if (ft_strncmp(cmd->file, "unset", 6) == 0)
	//     my_unset(sh, cmd, env);
	// else if (ft_strncmp(cmd->file, "env", 4) == 0)
	//     my_env(sh, cmd, env);
	// else if (ft_strncmp(cmd->file, "exit", 5) == 0)
	//     my_exit(sh, cmd, env);
}

int	env_built_in(t_sh *sh, char **env, t_comm *cmd)
{
	if (ft_strncmp(cmd->file, "cd", 3) == 0
		|| ft_strncmp(cmd->file, "export", 7) == 0
		|| ft_strncmp(cmd->file, "unset", 6) == 0
		|| ft_strncmp(cmd->file, "exit", 5) == 0)
	{
		check_built_in(sh, cmd, env, 0);
		return (0);
	}
	return (1);
}
