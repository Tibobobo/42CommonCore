/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:45:36 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/10 10:38:47 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	word_length(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '|' && s[i] != '<' && s[i] != '>'
		&& s[i] != ' ' && s[i] != '\t' && s[i] != '\n'
		&& !(s[i] == 34 && ft_strchr(&s[i + 1], 34) != NULL)
		&& !(s[i] == 39 && ft_strchr(&s[i + 1], 39) != NULL))
		i++;
	return (i);
}

int	token_length(char *s, int flag)
{
	int	i;

	i = 1;
	if (flag == 1 || flag == 2)
		return (flag);
	else if (flag == 34)
	{
		while (s[i] && s[i] != 34)
			i++;
		return (i + 1);
	}
	else if (flag == 39)
	{
		while (s[i] && s[i] != 39)
			i++;
		return (i + 1);
	}
	else
		return (word_length(s));
}

char	*copy_token(char *s, int flag)
{
	char	*token;
	int		i;
	int		tok_len;

	i = 0;
	tok_len = token_length(s, flag);
	token = malloc(sizeof(char) * (tok_len + 1));
	if (token == NULL)
		return (NULL);
	while (i < tok_len)
	{
		token[i] = s[i];
		i++;
	}
	token[i] = '\0';
	return (token);
}

void	lex_loop(t_sh *sh, int *i, int *j)
{
	while (sh->buf[*j] != '\0')
	{
		while (sh->buf[*j] == ' ' || sh->buf[*j] == '\t' || sh->buf[*j] == '\n')
			(*j)++;
		if (sh->buf[*j] == '\0')
			break ;
		if (sh->buf[*j] == '|')
			pipe_token(sh, i, j);
		else if (sh->buf[*j] == '<')
			in_redir_token(sh, i, j);
		else if (sh->buf[*j] == '>')
			out_redir_token(sh, i, j);
		else if (sh->buf[*j] == 34 && ft_strchr(&sh->buf[*j + 1], 34) != NULL)
			quote_token(sh, i, j, 34);
		else if (sh->buf[*j] == 39 && ft_strchr(&sh->buf[*j + 1], 39) != NULL)
			quote_token(sh, i, j, 39);
		else
			word_token(sh, i, j);
		if (sh->lex[*i] == NULL)
		{
			free_lex(sh);
			ft_error(sh, 1);
		}
		(*i)++;
	}
}

void	lexing(t_sh *sh)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	sh->lex = malloc(sizeof(char *) * (token_count(sh->buf) + 1));
	if (sh->lex == NULL)
		ft_error(sh, 1);
	lex_loop(sh, &i, &j);
	sh->lex[i] = NULL;
	free(sh->buf);
}
