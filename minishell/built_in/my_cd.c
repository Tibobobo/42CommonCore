/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:35:44 by tgrasset          #+#    #+#             */
/*   Updated: 2023/03/02 16:55:31 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_ret_val;

void	cd_error(t_sh *sh, t_comm *cmd, int forked, int type)
{
	if (type == 1)
	{
		ft_putstr_fd("msh: cd : ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (type == 2)
	{
		ft_putstr_fd("msh: cd : ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putendl_fd(": Not a directory", 2);
	}
	else if (type == 3)
	{
		ft_putstr_fd("msh: cd : ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	if (forked == 1)
	{
		free_lex(sh->env);
		free_all(sh);
		exit (1);
	}
	g_ret_val = 1;
}

void	update_pwd_vars(t_sh *sh, char *dir)
{
	char	*var;

	if (dir == NULL)
		return ;
	var = ft_getenv("OLDPWD", sh->env);
	if (var == NULL)
		cd_add_env_var(sh, "OLDPWD", dir);
	else
	{
		cd_replace_env_var(sh, "OLDPWD", dir);
		free(var);
	}
	dir = NULL;
	dir = getcwd(dir, 0);
	if (dir == NULL)
		return ;
	var = ft_getenv("PWD", sh->env);
	if (var == NULL)
		cd_add_env_var(sh, "PWD", dir);
	else
	{
		cd_replace_env_var(sh, "PWD", dir);
		free(var);
	}
}

void	cd_exit_child_process(t_sh *sh, char *current_dir)
{
	free_lex(sh->env);
	free_all(sh);
	if (current_dir != NULL)
		free(current_dir);
	exit (0);
}

void	change_directory(t_sh *sh, t_comm *cmd, int forked, char *current_dir)
{
	struct stat	buf;

	if (stat(cmd->argv[1], &buf) < 0 && errno == EACCES)
		cd_error(sh, cmd, forked, 3);
	else if (access(cmd->argv[1], F_OK) != 0)
		cd_error(sh, cmd, forked, 1);
	else if (S_ISDIR(buf.st_mode))
	{
		current_dir = getcwd(current_dir, 0);
		if (chdir(cmd->argv[1]) == -1)
		{
			if (current_dir != NULL)
				free(current_dir);
			cd_error(sh, cmd, forked, 3);
			return ;
		}
		if (forked == 1)
			cd_exit_child_process(sh, current_dir);
		update_pwd_vars(sh, current_dir);
		g_ret_val = 0;
		return ;
	}
	else
		cd_error(sh, cmd, forked, 2);
}

void	my_cd(t_sh *sh, t_comm *cmd, int forked)
{
	int		arg_nb;
	char	*current_dir;

	current_dir = NULL;
	arg_nb = check_cd_arg(cmd->argv);
	if (arg_nb > 2 || arg_nb == 1)
	{
		if (arg_nb > 2)
			ft_putendl_fd("msh: cd: too many arguments", 2);
		else
			ft_putendl_fd("msh: cd: missing argument: path to directory", 2);
		if (forked == 1)
		{
			free_lex(sh->env);
			free_all(sh);
			exit (1);
		}
		else
		{
			g_ret_val = 1;
			return ;
		}
	}
	change_directory(sh, cmd, forked, current_dir);
}
