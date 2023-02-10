/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:32:23 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/10 15:18:51 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	option_nbr(char **lex, int i)
{
	int	count;

	count = 0;
	i++;
	while (lex[i] != NULL && lex[i][0] != '|')
	{
		if (lex[i][0] != '<' && lex[i][0] != '>' && lex[i - 1][0] != '<'
				&& lex[i - 1][0] != '>')
			count++;
		i++;
	}
	return (count);
}

int	get_command_name(t_sh *sh, t_comm *new, int i)
{
	int	j;

	j = i;
	while (sh->lex[j] != NULL && sh->lex[j][0] != '|' && ((sh->lex[j][0] == '<'
		|| sh->lex[j][0] == '>') || (j != i && ((sh->lex[j - 1][0] == '<')
		|| sh->lex[j - 1][0] == '>'))))
		j++;
	if (sh->lex[j] == NULL || sh->lex[j][0] == '|')
		new->file = NULL;
	else
		new->file = sh->lex[j];
	return (j);
}

void	get_command_args(t_sh *sh, t_comm *new, int i)
{
	int	j;

	j = 0;
	new->argv = NULL;
	if (sh->lex[j] == NULL || sh->lex[j][0] == '|')
		return ;
	new->argv = malloc(sizeof(char *) * (option_nbr(sh->lex, i) + 1));
	if (new->argv == NULL)
		ft_error(sh, 1);
	i++;
	while (sh->lex[i] != NULL && sh->lex[i][0] != '|')
	{
		if (sh->lex[i][0] != '<' && sh->lex[i][0] != '>'
				&& sh->lex[i - 1][0] != '<' && sh->lex[i - 1][0] != '>')
		{
			new->argv[j] = sh->lex[i];
			j++;
		}
		i++;
	}
	new->argv[j] = NULL;
}
