/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:20:53 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/13 12:39:52 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_remove_2(char *new, char *str, int i, int j)
{
	while (str[i] != '\0')
	{
		while (str[i] == 34 || str[i] == 39)
			i++;
		new[j] = str[i];
		i++;
		j++;
	}
	new[i] = '\0';
}

char	*quote_remove(char *str, t_sh *sh)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == 34 || str[i] == 39)
			j++;
		i++;
	}
	new = malloc(sizeof(char) * (ft_strlen(str) - j + 1));
	if (new == NULL)
		ft_error(sh, 1);
	quote_remove_2(new, str, 0, 0);
	free(str);
	return (new);
}

void	clean_quotes(t_sh *sh)
{
	t_comm	*tmp;
	t_redir	*tmp2;
	int		i;

	tmp = sh->comm;
	while (tmp != NULL)
	{
		i = -1;
		tmp->file = quote_remove(tmp->file, sh);
		while (tmp->argv[++i] != NULL)
			tmp->argv[i] = quote_remove(tmp->argv[i], sh);
		tmp2 = tmp->in;
		while (tmp2 != NULL)
		{
			tmp2->name = quote_remove(tmp2->name, sh);
			tmp2 = tmp2->next;
		}
		tmp2 = tmp->out;
		while (tmp2 != NULL)
		{
			tmp2->name = quote_remove(tmp2->name, sh);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	remainder_length(char *str, int end)
{
	int	i;
	int	j;

	i = end;
	j = 0;
	while (str[end] != '\0')
	{
		end++;
		j++;
	}
	return (j);
}
