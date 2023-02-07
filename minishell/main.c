/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:29:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/07 10:52:54 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_error(int n)
{
    if (n == 1)
        ft_putstr_fd("Malloc error\n", 2);
    exit(-1);
}

int token_count(char *s)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
            i++;
        if (s[i] == '\0')
            break ;
        if (s[i] == '|')
            i++;
        else if (s[i] == '<')
        {
            if (s[i + 1] == '<')
                i = i + 2;
            else
                i++;
        }
        else if (s[i] == '>')
        {
            if (s[i + 1] == '>')
                i = i + 2;
            else
                i++;
        }
        else if (s[i] == '"' && ft_strchr(&s[i + 1], 34) != NULL)
        {
            i++;
            while (s[i] && s[i] != '"')
                i++;
            i++;
        }
        else if (s[i] == 39 && ft_strchr(&s[i + 1], 39) != NULL)
        {
            i++;
            while (s[i] && s[i] != '"')
                i++;
            i++;
        }
        else 
        {
            while (s[i] && s[i] != '|' && s[i] != '<' && s[i] != '>'
                && s[i] != ' ' && s[i] != '\t' && s[i] != '\n'
                && !(s[i] == 34 && ft_strchr(&s[i + 1], 34) != NULL)
                && !(s[i] == 39 && ft_strchr(&s[i + 1], 39) != NULL))
                i++;
        }
        count++;
    }
    return (count);
}

int     token_length(char *s, int flag)
{
    int i;

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
    {
        while (s[i] && s[i] != '|' && s[i] != '<' && s[i] != '>'
            && s[i] != ' ' && s[i] != '\t' && s[i] != '\n'
            && !(s[i] == 34 && ft_strchr(&s[i + 1], 34) != NULL)
            && !(s[i] == 39 && ft_strchr(&s[i + 1], 39) != NULL))
            i++;
        return (i);
    }
}

char    *copy_token(char *s, int flag)
{
    char    *token;
    int     i;
    int     tok_len;

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

void    free_lex(char **lex)
{
    int	i;

	i = 0;
	while (lex[i] != NULL)
	{
		free(lex[i]);
		i++;
	}
	free(lex);
	ft_error(1);
}

void lexing(t_sh *sh)
{
    int i;
    int j;

    i = 0;
    j = 0;
    sh->lex = malloc(sizeof(char *) * (token_count(sh->buf) + 1));
    if (sh->lex == NULL)
        ft_error(1);
    while (sh->buf[j] != '\0')
    {
        while (sh->buf[j] == ' ' || sh->buf[j] == '\t' || sh->buf[j] == '\n')
            j++;
        if (sh->buf[j] == '\0')
            break ;
        if (sh->buf[j] == '|')
        {
            sh->lex[i] = copy_token("|", 1);
            j++;
        }
        else if (sh->buf[j] == '<')
        {
            if (sh->buf[j + 1] == '<')
            {
                sh->lex[i] = copy_token("<<", 2);
                j = j + 2;
            }
            else
            {
                sh->lex[i] = copy_token("<", 1);
                j++;
            }
        }
        else if (sh->buf[j] == '>')
        {
            if (sh->buf[j + 1] == '>')
            {
                sh->lex[i] = copy_token(">>", 2);
                j = j + 2;
            }
            else
            {
                sh->lex[i] = copy_token(">", 1);
                j++;
            }
        }
        else if (sh->buf[j] == 34 && ft_strchr(&sh->buf[j + 1], 34) != NULL)
        {
            sh->lex[i] = copy_token(&sh->buf[j], 34);
            j++;
            while (sh->buf[j] && sh->buf[j] != 34)
                j++;
            j++;
        }
        else if (sh->buf[j] == 39 && ft_strchr(&sh->buf[j + 1], 39) != NULL)
        {
            sh->lex[i] = copy_token(&sh->buf[j], 39);
            j++;
            while (sh->buf[j] && sh->buf[j] != 39)
                j++;
            j++;
        }
        else 
        {
            sh->lex[i] = copy_token(&sh->buf[j], 42);
            while (sh->buf[j] && sh->buf[j] != '|' && sh->buf[j] != '<' && sh->buf[j] != '>'
                && sh->buf[j] != ' ' && sh->buf[j] != '\t' && sh->buf[j] != '\n'
                && !(sh->buf[j] == 34 && ft_strchr(&sh->buf[j + 1], 34) != NULL)
                && !(sh->buf[j] == 39 && ft_strchr(&sh->buf[j + 1], 39) != NULL))
                j++;
        }
        if (sh->lex[i] == NULL)
            return (free_lex(sh->lex));
        i++;
    }
    sh->lex[i] = NULL;
    free(sh->buf);
}

int main(int ac, char **av, char **env)
{
    t_sh    sh;
    int     i;

    (void)av;
    (void)env;
    (void)ac;
    while(1)
    {
        i = 0;
        sh.buf = readline("$>");
        lexing(&sh);
        while (sh.lex[i] != NULL)
        {
            printf("%s\n", sh.lex[i]);
            i++;
        }
    }
    return (0);
}