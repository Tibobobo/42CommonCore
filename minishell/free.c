/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:06:17 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/13 20:09:46 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redir(t_redir *redir)
{
	t_redir	*elem;
	t_redir	*next_elem;

	if (redir != NULL)
	{
		elem = redir;
		while (elem != NULL)
		{
			next_elem = elem->next;
			if (elem->name != NULL)
				free(elem->name);
			free(elem);
			elem = next_elem;
		}
	}
}

void	free_comm(t_comm *comm)
{
	t_comm	*elem;
	t_comm	*next_elem;

	if (comm == NULL)
		return ;
	elem = comm;
	while (elem != NULL)
	{
		next_elem = elem->next;
		free_lex(elem->argv);
		free_redir(elem->in);
        free_redir(elem->out);
		if (elem->file != NULL)
			free(elem->file);
		free(elem);
		elem = next_elem;
	}
}

int	ft_error(t_sh *sh, int n)
{
	if (sh->comm != NULL)
		free_comm(sh->comm);
	if (sh->buf != NULL)
		free(sh->buf);
	if (sh->lex != NULL)
		free_lex(sh->lex);
	rl_clear_history();
	if (n == 1)
		ft_putstr_fd("Malloc error\n", 2);
	exit(-1);
}

void	free_all(t_sh *sh)
{
	if (sh->comm != NULL)
		free_comm(sh->comm);
	if (sh->buf != NULL)
		free(sh->buf);
	if (sh->lex != NULL)
		free_lex(sh->lex);
}
