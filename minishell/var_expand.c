/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:14:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/10 22:21:37 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_exp(char *new, char *exp, int *i)
{
	int	j;

	j = 0;
	while (exp[j] != '\0')
	{
		new[*i] = exp[j];
		j++;
		(*i)++;
	}
}

char	*replace_2(char *str, char *exp, int start, int end)
{
	char	*new;
	int		i;

	i = -1;
	new = malloc(sizeof(char) * (start + ft_strlen(exp)
				+ remainder_length(str, end) + 1));
	if (new == NULL)
		return (NULL);
	while (++i < start)
		new[i] = str[i];
	if (exp != NULL)
		append_exp(new, exp, &i);
	while (str[end] != '\0')
	{
		new[i] = str[end];
		i++;
		end++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*replace_var(char *str, t_sh *sh, int start)
{
	int		end;
	char	var_name[1024];
	char	*exp;

	end = start + 1;
	if (str == NULL)
		return (NULL);
	while (str[end] && str[end] != ' ' && str[end] != '\t'
		&& str[end] != '\n' && str[end] != '$'
		&& !(str[0] == '"' && str[end] == '"'))
	{
		var_name[end - start - 1] = str[end];
		end++;
		if (end - start > 1023)
			return (str + end);
	}
	var_name[end - start - 1] = '\0';
	if (ft_strlen(var_name) == 0)
		return (str + end);
	exp = getenv(var_name);
	str = replace_2(str, exp, start, end);
	if (str == NULL)
		ft_error(sh, 1);
	return (str);
}

char	*var_check(char *str, t_sh *sh)
{
	int	i;

	i = 0;
	if (str == NULL || (str[0] == 39 && str[ft_strlen(str) - 1] == 39))
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] != '$' && str[i + 1] != ' '
			&& str[i + 1] != '\t' && str[i + 1] != '\n'
			&& str[i + 1] != '\0')
		{
			str = replace_var(str, sh, i);
			i = -1;
		}
		i++;
	}
	return (str);
}

void	expand_variables(t_sh *sh)
{
	t_comm	*tmp;
	t_redir	*tmp2;
	int		i;

	tmp = sh->comm;
	while (tmp != NULL)
	{
		i = -1;
		tmp->file = var_check(tmp->file, sh);
		while (tmp->argv[++i] != NULL)
			tmp->argv[i] = var_check(tmp->argv[i], sh);
		tmp2 = tmp->in;
		while (tmp2 != NULL)
		{
			tmp2->name = var_check(tmp2->name, sh);
			tmp2 = tmp2->next;
		}
		tmp2 = tmp->out;
		while (tmp2 != NULL)
		{
			tmp2->name = var_check(tmp2->name, sh);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
// $? double dollar
