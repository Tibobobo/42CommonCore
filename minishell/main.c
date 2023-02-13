/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:29:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/13 17:42:02 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redir(t_redir *in, t_redir *out)
{
	t_redir	*elem;
	t_redir	*next_elem;

	if (in != NULL)
	{
		elem = in;
		while (elem != NULL)
		{
			next_elem = elem->next;
			if (elem->name != NULL)
				free(elem->name);
			free(elem);
			elem = next_elem;
		}
	}
	if (out != NULL)
	{
		elem = out;
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
		free_redir(elem->in, elem->out);
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

int	main(int ac, char **av, char **env)
{
	t_sh	sh;
	// int		i;
	// int		j;

	(void)av;
	(void)ac;
	(void)env;
	while (1)
	{
		sh.lex = NULL;
		sh.comm = NULL;
		sh.buf = readline("minishell $> ");
		if (sh.buf[0] != '\0')
			add_history(sh.buf);
		if (ft_strncmp(sh.buf, "exit", 5) == 0)
		{
			rl_clear_history();
			free(sh.buf);
			return (0);
		}
		lexing(&sh);
		parsing(&sh);
		// i = 1;
		// while (sh.comm != NULL)
		// {
		// 	j = 0;
		// 	printf("COMMAND %d :\n", i);
		// 	printf("%s\n", sh.comm->file);
		// 	printf("OPTIONS :\n");
		// 	while (sh.comm->argv[j] != NULL)
		// 	{
		// 		printf("%s\n", sh.comm->argv[j]);
		// 		j++;
		// 	}
		// 	printf("INPUT REDIRECT\n");
		// 	while (sh.comm->in != NULL)
		// 	{
		// 		printf("%d  %s \n", sh.comm->in->doubl, sh.comm->in->name);
		// 		sh.comm->in = sh.comm->in->next;
		// 	}
		// 	printf("OUTPUT REDIRECT\n");
		// 	while (sh.comm->out != NULL)
		// 	{
		// 		printf("%d  %s \n", sh.comm->out->doubl, sh.comm->out->name);
		// 		sh.comm->out = sh.comm->out->next;
		// 	}
		// 	printf("\n\n");
		// 	sh.comm = sh.comm->next;
		// 	i++;
		// }
		// if (sh.comm != NULL)
		// 	execute(&sh);
		free_all(&sh);
	}
	return (0);
}