/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:32:23 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:22 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	option_nbr(char **lex, int i)
{
	int	count;

	count = 0;
	if (lex[i] != NULL && lex[i][0] != '|')
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
	new->argv = malloc(sizeof(char *) * (option_nbr(sh->lex, i) + 1));
	if (new->argv == NULL)
		ft_error(sh, 1);
	if (new->file != NULL)
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

void	syntax_error(int i)
{
	if (i == 1)
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
	if (i == 2)
		ft_putendl_fd("minishell: syntax error near unexpected token `newline'", 2);
	if (i == 3)
		ft_putendl_fd("minishell: syntax error near unexpected token `<'", 2);
	if (i == 4)
		ft_putendl_fd("minishell: syntax error near unexpected token `>'", 2);
	if (i == 5)
		ft_putendl_fd("minishell: syntax error near unexpected token `<<'", 2);
	if (i == 6)
		ft_putendl_fd("minishell: syntax error near unexpected token `>>'", 2);
}

int	check_syntax(char **lex, int i)
{
	if (lex[0][0] == '|')
		return (syntax_error(1), -1);
	if ((lex[0][0] == '<' || lex[0][0] == '>') && lex[1] == NULL)
		return (syntax_error(2), -1);
	while (lex[i] != NULL)
	{
		if ((lex[i - 1][0] == '<' || lex[i - 1][0] == '>' || lex[i - 1][0] == '|')
			&& lex[i][0] == '|')
			return (syntax_error(1), -1);
		if ((lex[i - 1][0] == '<' || lex[i - 1][0] == '>') && lex[i][0] == '<')
		{
			if (lex[i][1] == '<')
				return (syntax_error(5), -1);
			return (syntax_error(3), -1);
		}
		if ((lex[i - 1][0] == '<' || lex[i - 1][0] == '>') && lex[i][0] == '>')
		{
			if (lex[i][1] == '>')
				return (syntax_error(6), -1);
			return (syntax_error(4), -1);
		}
		if ((lex[i][0] == '<' || lex[i][0] == '>') && lex[i + 1] == NULL)
			return (syntax_error(2), -1);
		i++;
	}
	return (0);
}

//ATTENTION NOM JUSTE QUOTE CA VA PETER