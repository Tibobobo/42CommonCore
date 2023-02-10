/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:20:53 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/10 22:51:08 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quote_remove(char *str, t_sh *sh)
{
	char	*new;
	int		i;
	int		len;
	
	i = 0;
	len = ft_strlen(str);
	if (!((str[0] == 34 && str[len - 1] == 34)
		|| (str[0] == 39 && str[len - 1] == 39)))
		return (str);
	new = malloc(sizeof(char) * (len - 1));
	if (new == NULL)
		ft_error(sh, 1);
	while (i < len - 2)
	{
		new[i] = str[i + 1];
		i++;
	}
	new[i] = '\0';
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
