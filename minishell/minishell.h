/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:13 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/13 13:00:57 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include "./libft/libft.h"

typedef struct s_redir
{
	char			*name;
	int				doubl;
	struct s_redir	*next;
}			t_redir;

typedef struct s_comm
{
	char			*file;
	char			**argv;
	t_redir			*in;
	t_redir			*out;
	struct s_comm	*next;
}			t_comm;

typedef struct s_sh
{
	char	*buf;
	char	**lex;
	t_comm	*comm;
}			t_sh;

int		ft_error(t_sh *sh, int n);
void	lexing(t_sh *sh);
int		token_count(char *s);
void	free_lex(t_sh *sh);
void	pipe_token(t_sh *sh, int *i, int *j);
void	in_redir_token(t_sh *sh, int *i, int *j);
void	out_redir_token(t_sh *sh, int *i, int *j);
void	quote_token(t_sh *sh, int *i, int *j, int type);
void	word_token(t_sh *sh, int *i, int *j);
char	*copy_token(char *s, int flag);
void	parsing(t_sh *sh);
void	free_comm(t_comm **comm);
int		get_command_name(t_sh *sh, t_comm *new, int i);
void	get_command_args(t_sh *sh, t_comm *new, int i);
void	expand_variables(t_sh *sh);
int		remainder_length(char *str, int end);
void	clean_quotes(t_sh *sh);
void	skip_quotes(char *s, int *i, int type);
int		check_syntax(char **lex, int i);

#endif
