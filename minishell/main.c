/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:29:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/14 18:48:16 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler_prompt(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();         //$? = 130
	}
	if (signum == SIGQUIT)
	{
		printf("\33[2K\r");
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int ac, char **av, char **env)
{
	t_sh	sh;

	(void)av;
	(void)ac;
	signal(SIGINT, sig_handler_prompt);
	signal(SIGQUIT, sig_handler_prompt);
	while (1)
	{
		sh.lex = NULL;
		sh.comm = NULL;
		sh.buf = readline("minishell $> ");
		if (sh.buf == NULL || ft_strncmp(sh.buf, "exit", 5) == 0)
		{
			rl_clear_history();
			if (sh.buf != NULL)
				free(sh.buf);
			printf("exit\n");
			return (0);
		}
		if (sh.buf[0] != '\0')
			add_history(sh.buf);
		lexing(&sh);
		parsing(&sh);
		if (sh.comm != NULL)
			execution(&sh, env);
		free_all(&sh);
	}
	return (0);
}

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
		// 	printf("REDIRECT\n");
		// 	while (sh.comm->redir != NULL)
		// 	{
		// 		printf("double: %d  output: %d   %s\n", sh.comm->redir->doubl, sh.comm->redir->output, sh.comm->redir->name);
		// 		sh.comm->redir = sh.comm->redir->next;
		// 	}
		// 	printf("\n");
		// 	sh.comm = sh.comm->next;
		// 	i++;
		// }