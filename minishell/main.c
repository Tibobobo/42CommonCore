/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:29:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/09 10:31:19 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(t_sh *sh, int n)
{
	if (sh->buf != NULL)
		free(sh->buf);
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
		i = 0;
		sh.buf = readline("minishell-test$> ");
		if (sh.buf[0] != '\0')
			add_history(sh.buf);
		lexing(&sh);
		parsing(&sh);
		// while (sh.lex[i] != NULL)
		// {
		// 	printf("%s\n", sh.lex[i]);
		// 	i++;
		// }
	}
	return (0);
}
