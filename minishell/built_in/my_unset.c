/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:33:51 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/28 16:37:07 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_ret_val;

int	var_position(char *name, char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL
		&& ft_strnstr(env[i], name, ft_strlen(name) + 1) == NULL)
		i++;
	if (env[i] == NULL)
		return (-1);
	return (i);
}

int	env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}

void	remove_var_from_env(t_sh *sh, int pos)
{
	char	**newenv;
	int		i;
	int		j;

	newenv = malloc(sizeof(char *) * env_len(sh->env));
	if (newenv == NULL)
		ft_error(sh, 1);
	i = 0;
	j = 0;
	while (sh->env[i] != NULL)
	{
		if (i != pos)
			newenv[j] = sh->env[i];
		else
			j--;
		i++;
		j++;
	}
	newenv[j] = NULL;
	free(sh->env);
	sh->env = newenv;
}

void	my_unset(t_sh *sh, t_comm *cmd, int forked)
{
	int	pos;
	int	i;

	i = 1;
	while (cmd->argv[i] != NULL)
	{
		pos = var_position(cmd->argv[i], sh->env);
		if (pos >= 0)
			remove_var_from_env(sh, pos);
		i++;
	}
	if (forked == 1)
	{
		free_lex(sh->env);
		free_all(sh);
		exit (0);
	}
	g_ret_val = 0;
	return ;
}
