/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:29:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/27 18:30:17 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_ret_val = 0;

void	sig_handler_command(int signum)
{
	if (signum == SIGINT)
		printf("\n");
	if (signum == SIGQUIT)
		printf("Quit (core dumped)\n");
}

void	sig_handler_prompt(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_ret_val = 130;
	}
	if (signum == SIGQUIT)
	{
		printf("\33[2K\r");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	lex_parse_execute_free(t_sh *sh, char **env)
{
	lexing(sh);
	parsing(sh);
	sh->stdin_save = dup(0);
	if (sh->stdin_save < 0)
		ft_error(sh, 3);
	if (sh->comm != NULL)
	{
		execution(sh, env);
		wait_for_children(sh);
		signal(SIGINT, sig_handler_prompt);
		signal(SIGQUIT, sig_handler_prompt);
	}
	free_all(sh);
	if (dup2(sh->stdin_save, 0) < 0)
		ft_error(sh, 3);
	close(sh->stdin_save);
}

int	main(int ac, char **av, char **envp)
{
	t_sh	sh;

	(void)av;
	(void)ac;
	g_ret_val = 0;
	sh.env = setup_env(envp);
	signal(SIGINT, sig_handler_prompt);
	signal(SIGQUIT, sig_handler_prompt);
	signal(SIGTSTP, SIG_IGN);
	while (1)
	{
		sh.buf = readline("\033[0;32mminishell $> \033[0;m");
		if (sh.buf == NULL)
		{
			rl_clear_history();
			free_all(&sh);
			free_lex(sh.env);
			ft_putendl_fd("exit", 1);
			break ;
		}
		if (sh.buf[0] != '\0')
			add_history(sh.buf);
		lex_parse_execute_free(&sh, sh.env);
	}
	return (0);
}
