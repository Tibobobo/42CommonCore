/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:28:12 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/13 10:18:40 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_in_redir(t_sh *sh, t_comm *cmd, int i)
{
	t_redir	*new;
	t_redir	*tmp;

	tmp = cmd->in;
	new = malloc(sizeof(t_redir));
	if (new == NULL)
		ft_error(sh, 1);
	if (ft_strlen(sh->lex[i]) == 1)
		new->doubl = 0;
	else
		new->doubl = 1;
	if (sh->lex[i + 1] == NULL || sh->lex[i + 1][0] == '<'
		|| sh->lex[i + 1][0] == '>' || sh->lex[i + 1][0] == '|')
		new->name = NULL;
	else
		new->name = sh->lex[i + 1];
	new->next = NULL;
	if (cmd->in == NULL)
		cmd->in = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	add_out_redir(t_sh *sh, t_comm *cmd, int i)
{
	t_redir	*new;
	t_redir	*tmp;

	tmp = cmd->out;
	new = malloc(sizeof(t_redir));
	if (new == NULL)
		ft_error(sh, 1);
	if (ft_strlen(sh->lex[i]) == 1)
		new->doubl = 0;
	else
		new->doubl = 1;
	if (sh->lex[i + 1] == NULL || sh->lex[i + 1][0] == '<'
		|| sh->lex[i + 1][0] == '>' || sh->lex[i + 1][0] == '|')
		new->name = NULL;
	else
		new->name = sh->lex[i + 1];
	new->next = NULL;
	if (cmd->out == NULL)
		cmd->out = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	get_redirections(t_sh *sh, t_comm *cmd, int i)
{
	int	j;

	j = i;
	while (sh->lex[j] != NULL && sh->lex[j][0] != '|')
	{
		if (sh->lex[j][0] == '<')
			add_in_redir(sh, cmd, j);
		j++;
	}
	j = i;
	while (sh->lex[j] != NULL && sh->lex[j][0] != '|')
	{
		if (sh->lex[j][0] == '>')
			add_out_redir(sh, cmd, j);
		j++;
	}
}

int	add_command(t_sh *sh, int i)
{
	t_comm	*new;
	t_comm	*tmp;

	if (sh->lex[i][0] == '|')
		return (1);
	tmp = sh->comm;
	new = malloc(sizeof(t_comm));
	if (new == NULL)
		ft_error(sh, 1);
	new->next = NULL;
	if (sh->comm == NULL)
		sh->comm = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	new->in = NULL;
	new->out = NULL;
	get_redirections(sh, new, i);
	get_command_args(sh, new, get_command_name(sh, new, i));
	return (0);
}

void	parsing(t_sh *sh)
{
	int	i;

	sh->comm = NULL;
	i = 0;
	while (sh->lex[i] != NULL)
	{
		if (add_command(sh, i) != 0)
		{
			free_comm(&sh->comm);
			return ;
		}
		while (sh->lex[i] != NULL && sh->lex[i][0] != '|')
			i++;
		if (sh->lex[i] != NULL)
			i++;
	}
	expand_variables(sh);
	clean_quotes(sh);
}
