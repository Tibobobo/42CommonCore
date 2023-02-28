/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:54:08 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/28 15:14:51 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var_name(t_sh *sh, t_comm *cmd)
{
	int		i;
	char	*res;

	i = 0;
	while (cmd->argv[1][i] != '\0' && cmd->argv[1][i] != '=')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		ft_error(sh, 1);
	i = 0;
	while (cmd->argv[1][i] != '\0' && cmd->argv[1][i] != '=')
	{
		res[i] = cmd->argv[1][i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_new_value(t_sh *sh, t_comm *cm, char *name)
{
	int		i;
	int		j;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(cm->argv[1]) - ft_strlen(name) + 1));
	if (res == NULL)
	{
		free(name);
		ft_error(sh, 1);
	}
	i = 0;
	j = 0;
	while (cm->argv[1][i] != '\0' && cm->argv[1][i] != '=')
		i++;
	if (cm->argv[1][i] == '=')
		i++;
	while (cm->argv[1][i] != '\0')
	{
		res[j] = cm->argv[1][i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	copy_new_var(char *new, char *name, char *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (name[i] != '\0')
	{
		new[i] = name[i];
		i++;
	}
	new[i] = '=';
	i++;
	while (value[j] != '\0')
	{
		new[i] = value[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(name);
	free(value);
}

void	replace_env(t_sh *sh, char **newenv, char *new)
{
	int	i;

	i = 0;
	while (sh->env[i] != NULL)
	{
		newenv[i] = ft_strdup(sh->env[i]);
		if (newenv[i] == NULL)
		{
			free(new);
			free_lex(newenv);
			ft_error(sh, 1);
		}
		i++;
	}
	newenv[i] = new;
	newenv[i + 1] = NULL;
	free_lex(sh->env);
	sh->env = newenv;
}
