/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:08:40 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/16 13:12:04 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	remainder_length(char *str, int end)
{
	int	i;
	int	j;

	i = end;
	j = 0;
	if (str[end] == '}')
		end++;
	while (str[end] != '\0')
	{
		end++;
		j++;
	}
	return (j);
}

int	get_var_name_len(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '{' && ft_strchr(str, '}') != NULL)
	{
		while (str[i] != '}')
			i++;
		return (i);
	}
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
		&& str[i] != '$' && str[i] != ']' && str[i] != 34 && str[i] != 39)
		i++;
	return (i);
}

void	copy_brackets_var(char *str, char *var_name, int *end, int start)
{
	(*end)++;
	while (str[*end] != '}')
	{
		var_name[*end - start - 2] = str[*end];
		(*end)++;
	}
	var_name[*end - start - 2] = '\0';
}

void	copy_nobrackets_var(char *str, char *var_name, int *end, int start)
{
	while (str[*end] && str[*end] != ' ' && str[*end] != '\t'
		&& str[*end] != '\n' && str[*end] != '$' && str[*end] != 34
		&& str[*end] != 39 && str[*end] != ']')
	{
		var_name[*end - start - 1] = str[*end];
		(*end)++;
	}
	var_name[*end - start - 1] = '\0';
}
