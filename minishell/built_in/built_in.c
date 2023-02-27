/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:39:32 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/27 11:35:36 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    check_built_in(t_sh *sh, t_comm *cmd, char **env)
{
    if (ft_strncmp(cmd->file, "echo", 5) == 0)
        my_echo(sh, cmd, env);
    // else if (ft_strncmp(cmd->file, "cd", 3) == 0)
    //     my_cd(sh, cmd, env);
    // else if (ft_strncmp(cmd->file, "pwd", 4) == 0)
    //     my_pwd(sh, cmd, env);
    // else if (ft_strncmp(cmd->file, "export", 7) == 0)
    //     my_export(sh, cmd, env);
    // else if (ft_strncmp(cmd->file, "unset", 6) == 0)
    //     my_unset(sh, cmd, env);
    // else if (ft_strncmp(cmd->file, "env", 4) == 0)
    //     my_env(sh, cmd, env);
    // else if (ft_strncmp(cmd->file, "exit", 5) == 0)
    //     my_exit(sh, cmd, env);
}