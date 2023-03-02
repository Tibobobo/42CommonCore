/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:50:21 by tgrasset          #+#    #+#             */
/*   Updated: 2023/03/02 16:55:37 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_replace_env_var(t_sh *sh, char *name, char *value)
{
	int		i;
	char	*new;

	i = 0;
	while (sh->env[i] != NULL
		&& !(ft_strncmp(sh->env[i], name, ft_strlen(name)) == 0
			&& sh->env[i][ft_strlen(name)] == '='))
		i++;
	new = malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(value) + 2));
	if (new == NULL)
	{
		free(value);
		ft_error(sh, 1);
	}
	free(sh->env[i]);
	copy_new_var(new, name, value);
	sh->env[i] = new;
}

void	cd_add_env_var(t_sh *sh, char *name, char *value)
{
	char	*new;
	char	**newenv;
	int		i;

	new = malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(value) + 2));
	if (new == NULL)
	{
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
		free(value);
		ft_error(sh, 1);
	}
	replace_env(sh, newenv, new);
}

int	check_cd_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}
