/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:35:44 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/27 16:02:59 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_ret_val;

void	non_existent_directory(t_sh *sh, t_comm *cmd, int forked, int type)
{
	if (type == 1)
	{
		ft_putstr_fd("msh: cd : ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		if (forked == 1)
		{
			free_all(sh);
			exit (1);
		}
	}
	else
	{
		ft_putstr_fd("msh: cd : ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putendl_fd(": Not a directory", 2);
		if (forked == 1)
		{
			free_all(sh);
			exit (1);
		}
	}
	g_ret_val = 1;
}

void	change_directory(t_sh *sh, t_comm *cmd, int forked)
{
	struct stat	buf;

	if (access(cmd->argv[1], F_OK) != 0)
	{
		non_existent_directory(sh, cmd, forked, 1);
		return ;
	}
	if (stat(cmd->argv[1], &buf) < 0)
		ft_error(sh, 6);
	if (S_ISDIR(buf.st_mode))
	{
		chdir(cmd->argv[1]);
		if (forked == 1)
			exit (0);
		g_ret_val = 0;
		return ;
	}
	else
		non_existent_directory(sh, cmd, forked, 2);
}

int	check_cd_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

void	my_cd(t_sh *sh, t_comm *cmd, char **env, int forked)
{
	int	arg_nb;

	(void)env;
	arg_nb = check_cd_arg(cmd->argv);
	if (arg_nb > 2 || arg_nb == 1)
	{
		if (arg_nb > 2)
			ft_putendl_fd("msh: cd: too many arguments", 2);
		else
			ft_putendl_fd("msh: cd: missing argument", 2);
		if (forked == 1)
		{
			free_all(sh);
			exit (1);
		}
		else
		{
			g_ret_val = 1;
			return ;
		}
	}
	else
		change_directory(sh, cmd, forked);
}
