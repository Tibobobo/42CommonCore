/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:52:50 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/28 17:25:29 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_ret_val;

int	check_export_cmd_format(t_sh *sh, t_comm *cmd, int forked)
{
	int	i;

	i = 0;
	while (cmd->argv[i] != NULL)
		i++;
	if (i == 1)
	{
		ft_putendl_fd("msh: export: Usage : export name[=value]", 2);
		if (forked == 1)
		{
			free_lex(sh->env);
			free_all(sh);
			exit (1);
		}
		g_ret_val = 1;
		return (1);
	}
	return (0);
}

int	check_export_var_name(t_sh *sh, char *arg, int forked)
{
	int	i;

	i = 1;
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if ((!(ft_isalpha(arg[0])) && arg[0] != '_')
			|| (!(ft_isalnum(arg[i])) && arg[i] != '_'))
		{
			ft_putstr_fd("msh: export: `", 2);
			ft_putstr_fd(arg, 2);
			ft_putendl_fd("': not a valid identifier", 2);
			if (forked == 1)
			{
				free_lex(sh->env);
				free_all(sh);
				exit (1);
			}
			g_ret_val = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	replace_existing_var(t_sh *sh, char *arg, char *name, char *val)
{
	int	i;

	i = 0;
	while (ft_strnstr(sh->env[i], name, ft_strlen(name) + 1) == NULL)
		i++;
	free(sh->env[i]);
	val = get_new_value(sh, arg, name);
	sh->env[i] = malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(val) + 2));
	if (sh->env[i] == NULL)
	{
		free(name);
		free(val);
		ft_error(sh, 1);
	}
	copy_new_var(sh->env[i], name, val);
}

void	add_new_env_var(t_sh *sh, char *arg, char *name, char *value)
{
	char	*new;
	char	**newenv;
	int		i;

	value = get_new_value(sh, arg, name);
	new = malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(value) + 2));
	if (new == NULL)
	{
		free(name);
		free(value);
		ft_error(sh, 1);
	}
	copy_new_var(new, name, value);
	i = 0;
	while (sh->env[i] != NULL)
		i++;
	newenv = malloc(sizeof(char *) * (i + 2));
	if (newenv == NULL)
	{
		free(name);
		free(value);
		ft_error(sh, 1);
	}
	replace_env(sh, newenv, new);
}

void	my_export(t_sh *sh, t_comm *cmd, int forked)
{
	char	*name;
	char	*value;
	int		i;

	value = NULL;
	if (check_export_cmd_format(sh, cmd, forked) == 1)
		return ;
	i = 1;
	while (cmd->argv[i] != NULL)
	{
		if (check_export_var_name(sh, cmd->argv[i], forked) == 1)
			return ;
		name = get_var_name(sh, cmd->argv[i]);
		value = ft_getenv(name, sh->env);
		if (value != NULL)
		{
			free(value);
			replace_existing_var(sh, cmd->argv[i], name, value);
		}
		else
			add_new_env_var(sh, cmd->argv[i], name, value);
		i++;
	}
	finish_forked_export(sh, forked);
	g_ret_val = 0;
}
