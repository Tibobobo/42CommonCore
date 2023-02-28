/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:52:50 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/28 15:11:58 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_ret_val;

int	check_export_cmd_format(t_sh *sh, t_comm *cmd, char **env, int forked)
{
	int	i;

	i = 0;
	while (cmd->argv[i] != NULL)
		i++;
	if (i == 1 || i > 2)
	{
		ft_putendl_fd("msh: export: Usage : export name[=value]", 2);
		if (forked == 1)
		{
			free_all(sh);
			free_lex(env);
			exit (1);
		}
		g_ret_val = 1;
		return (1);
	}
	return (0);
}

int	check_export_var_name(t_sh *sh, t_comm *cmd, char **env, int forked)
{
	int	i;

	i = 1;
	while (cmd->argv[1][i] != '\0' && cmd->argv[1][i] != '=')
	{
		if ((!(ft_isalpha(cmd->argv[1][0])) && cmd->argv[1][0] != '_')
			|| (!(ft_isalnum(cmd->argv[1][i])) && cmd->argv[1][i] != '_'))
		{
			ft_putstr_fd("msh: export: `", 2);
			ft_putstr_fd(cmd->argv[1], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			if (forked == 1)
			{
				free_all(sh);
				free_lex(env);
				exit (1);
			}
			g_ret_val = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	replace_existing_var(t_sh *sh, t_comm *cmd, char *name, char *val)
{
	int	i;

	i = 0;
	while (ft_strnstr(sh->env[i], name, ft_strlen(name) + 1) == NULL)
		i++;
	free(sh->env[i]);
	val = get_new_value(sh, cmd, name);
	sh->env[i] = malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(val) + 2));
	if (sh->env[i] == NULL)
	{
		free(name);
		free(val);
		ft_error(sh, 1);
	}
	copy_new_var(sh->env[i], name, val);
}

void	add_new_env_var(t_sh *sh, t_comm *cmd, char *name, char *value)
{
	char	*new;
	char	**newenv;
	int		i;

	value = get_new_value(sh, cmd, name);
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

void	my_export(t_sh *sh, t_comm *cmd, char **env, int forked)
{
	char	*name;
	char	*value;

	value = NULL;
	if (check_export_cmd_format(sh, cmd, env, forked)
		|| check_export_var_name(sh, cmd, env, forked))
		return ;
	name = get_var_name(sh, cmd);
	value = ft_getenv(name, env);
	if (value != NULL)
	{
		free(value);
		replace_existing_var(sh, cmd, name, value);
	}
	else
		add_new_env_var(sh, cmd, name, value);
	if (forked == 1)
	{
		free_lex(sh->env);
		free_all(sh);
		exit (0);
	}
	g_ret_val = 0;
}
