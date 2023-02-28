/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:14:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/28 13:50:46 by tgrasset         ###   ########.fr       */
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
	if (str[end] && str[end] == '}')
		end++;
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

static char	*replace_var(char *str, t_sh *sh, int start)
{
	int		end;
	char	*var_name;
	char	*exp;

	end = start + 1;
	var_name = malloc(sizeof(char) * (get_var_name_len(&str[end]) + 1));
	if (var_name == NULL)
		ft_error(sh, 1);
	if (str[end] == '{' && ft_strchr(str, '}') != NULL)
		copy_brackets_var(str, var_name, &end, start);
	else
		copy_nobrackets_var(str, var_name, &end, start);
	if (var_name[0] == '?' && var_name[1] == '\0')
	{
		free(var_name);
		return (replace_by_ret_value(sh, str, start, end));
	}
	exp = ft_getenv(var_name, sh->env);
	free(var_name);
	str = replace_2(str, exp, start, end);
	if (exp != NULL)
		free(exp);
	if (str == NULL)
		ft_error(sh, 1);
	return (str);
}

static char	*var_check(char *str, t_sh *sh)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == 39 && ft_strchr(&str[i + 1], 39) != NULL)
			skip_quotes(str, &i, 39);
		if (str[i] && str[i] == '$' && str[i + 1] != '$' && str[i + 1] != ' '
			&& str[i + 1] != '\t' && str[i + 1] != '\n'
			&& str[i + 1] != '\0')
		{
			str = replace_var(str, sh, i);
			if (i != 0)
				i--;
		}
		if (str[i] != '\0')
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
		tmp2 = tmp->redir;
		while (tmp2 != NULL)
		{
			tmp2->name = var_check(tmp2->name, sh);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
