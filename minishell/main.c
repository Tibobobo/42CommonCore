/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:29:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/10 10:47:36 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redir(t_redir **in, t_redir **out)
{
	t_redir	*elem;
	t_redir	*next_elem;

	if (*in != NULL)
	{
		elem = *in;
		while (elem != NULL)
		{
			next_elem = elem->next;
			free(elem);
			elem = next_elem;
		}
		in = NULL;
	}
	if (*out != NULL)
	{
		elem = *out;
		while (elem != NULL)
		{
			next_elem = elem->next;
			free(elem);
			elem = next_elem;
		}
		out = NULL;
	}
}

void	free_comm(t_comm **comm)
{
	t_comm	*elem;
	t_comm	*next_elem;

	if (*comm == NULL)
		return ;
	elem = *comm;
	while (elem != NULL)
	{
		next_elem = elem->next;
		free_redir(&elem->in, &elem->out);
		free(elem);
		elem = next_elem;
	}
	*comm = NULL;
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
				printf("%d  %s \n", sh.comm->in->doubl, sh.comm->in->name);
				sh.comm->in = sh.comm->in->next;
			}
			printf("OUT\n\n");
			while (sh.comm->out != NULL)
			{
				printf("%d  %s \n", sh.comm->out->doubl, sh.comm->out->name);
				sh.comm->out = sh.comm->out->next;
			}
			sh.comm = sh.comm->next;
			i++;
		}
	}
	return (0);
}
