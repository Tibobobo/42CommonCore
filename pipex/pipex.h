/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:47:42 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/13 13:27:04 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "./libft/libft.h"

int		ft_error(int num, char **split, char **split2);
void	free_split(char **split);
int		command_error(char **command);
char	**split_paths(char **args, char **env);
char	*get_path(char **args, char **env);
void	childsplay(int	*pipe_fd);
void	redirect(char *command, int fdin, char **env);
void	exec(char *command, char **env);
void	fds_check_and_dup(int *fdin, int *fdout);

#endif
