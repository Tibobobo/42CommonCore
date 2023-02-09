/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:29:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/09 18:23:13 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_comm(t_comm **comm)
{
	t_comm *elem;
	t_comm *next_elem;

	if (*comm == NULL)
		return ;
	elem = *comm;
	while (elem != NULL)
	{
		next_elem = elem->next;
		free(elem);					//free les t_redir
		elem = next_elem;
	}
	*comm = NULL;
}

void	add_in_redir(t_sh *sh, t_comm *cmd, int i)
{
	t_redir *new;
	t_redir *tmp;

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
	t_redir *new;
	t_redir *tmp;

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
	j = 0;
	while (sh->lex[j] != NULL && sh->lex[j][0] != '|')
	{
		if (sh->lex[j][0] =='>')
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
	// get_command_name(sh, new, i);
	// get_command_args(sh, new, i);
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
		}
		while (sh->lex[i] != NULL && sh->lex[i][0] != '|')
			i++;
		if (sh->lex[i] != NULL)
			i++;
	}
}

int	ft_error(t_sh *sh, int n)
{
	if (sh->comm != NULL)
		free_comm(&sh->comm);
	if (sh->buf != NULL)
		free(sh->buf);
	if (sh->lex != NULL)
		free_lex(sh);
	if (n == 1)
		ft_putstr_fd("Malloc error\n", 2);
	exit(-1);
}

int	main(int ac, char **av, char **env)
{
	t_sh	sh;
	int		i;

	(void)av;
	(void)env;
	(void)ac;
	while (1)
	{
		i = 1;
		sh.buf = readline("minishell-test$> ");
		if (sh.buf[0] != '\0')
			add_history(sh.buf);
		lexing(&sh);
		parsing(&sh);
		while (sh.comm != NULL)
		{
			printf("COMMAND %d\n\n", i);
			printf("IN\n\n");
			while (sh.comm->in != NULL)
			{
				printf("%d   \n", sh.comm->in->doubl);
				printf("%s    \n", sh.comm->in->name);
				sh.comm->in = sh.comm->in->next;
			}
			printf("OUT\n\n");
			while (sh.comm->out != NULL)
			{
				printf("%d   \n", sh.comm->out->doubl);
				printf("%s    \n", sh.comm->out->name);
				sh.comm->out = sh.comm->out->next;
			}
			sh.comm = sh.comm->next;			//quelques prob pour afficher les OUT notamment
			i++;
		}
	}
	return (0);
}