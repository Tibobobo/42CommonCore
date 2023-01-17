/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:25:37 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/13 17:30:15 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

int		ft_error(int num, char **split, char **split2);
void	free_split(char **split);
int		command_error(char **command);
char	**split_paths(char **args, char **env);
char	*get_path(char **args, char **env);
void	here_doc(int ac, char **av, char **env, int fdout);
void	parenting_task(int	*pipe_fd);
void	redirect(char *command, int fdin, char **env);
void	exec(char *command, char **env);
void	fds_check_and_dup(int *fdin, int *fdout);

#endif
