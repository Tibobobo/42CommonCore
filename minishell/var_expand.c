/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:14:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/10 20:46:08 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int remainder_length(char *str, int end)
{
    int i;
    int j;

    i = end;
    j = 0;
    while (str[end] != '\0')
    {
        end++;
        j++;
    }
    return (j);
}

void    append_exp(char *new, char *exp, int *i)
{
    int j;

    j = 0;
    while (exp[j] != '\0')
    {
        new[*i] = exp[j];
        j++;
        (*i)++;
    }
}

char    *replace_2(char *str, char *exp, int start, int end)
{
    char    *new;
    int     i;

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

void    replace_var(char *str, t_sh *sh, int start)
{
    int     end;
    char    var_name[1024];
    char    *exp;

    end = start + 1;
    if (str == NULL)
        return ;
    while (str[end] && str[end] != ' ' && str[end] != '\t'
        && str[end] != '\n' && str[end] != '$')
    {
        var_name[end - start - 1] = str[end];
        end++;
        if (end - start > 1023)
            return ;
    }
    var_name[end - start - 1] = '\0';
    if (ft_strlen(var_name) == 0)
        return ;
    exp = getenv(var_name);
    str = replace_2(str, exp, start, end);
    if (str == NULL)
        ft_error(sh, 1);
}

void    var_check(char *str, t_sh *sh)
{
    int i;

    i = 0;
    if (str == NULL || (str[0] == 39 && str[ft_strlen(str) - 1] == 39))
        return ;
    while (str[i] != '\0')
    {
        if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\t'
            && str[i + 1] != '\n' && str[i + 1] != '\0')
            replace_var(str, sh, i);                //cas de $?
        i++;
    }
}

void    expand_variables(t_sh *sh)
{
    t_comm  *tmp;
    t_redir *tmp2;
    int     i;

    tmp = sh->comm;
    while (tmp != NULL)
    {
        i = -1;
        var_check(sh->comm->file, sh);
        while (sh->comm->argv[++i] != NULL)
            var_check(sh->comm->argv[i], sh);
        tmp2 = sh->comm->in;
        while (tmp2 != NULL)
        {
            var_check(tmp2->name, sh);
            tmp2 = tmp2->next;
        }
        tmp2 = sh->comm->out;
        while (tmp2 != NULL)
        {
            var_check(tmp2->name, sh);
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}