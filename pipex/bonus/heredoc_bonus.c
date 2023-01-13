/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:18:01 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/13 17:30:44 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_loop(char *line, char *limiter)
{
	while (1)
	{
		ft_putstr_fd("pipex heredoc> ", 2);
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			exit(1);
		}
		ft_putstr_fd(line, 1);
		free(line);
	}
}

void	redirect_gnl(char *limiter)
{
	pid_t	pid;
	int		pipe_fd[2];
	char	*line;

	line = NULL;
	if (pipe(pipe_fd) < 0)
		ft_error(2, NULL, NULL);
	pid = fork();
	if (pid < 0)
		ft_error(3, NULL, NULL);
	else if (pid != 0)
	{
		parenting_task(pipe_fd);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], 1) < 0)
			ft_error(6, NULL, NULL);
		close(pipe_fd[1]);
		here_doc_loop(line, limiter);
	}
}

void	here_doc(int ac, char **av, char **env, int fdout)
{
	int	i;

	i = 3;
	fdout = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fdout < 0)
		ft_error(5, NULL, NULL);
	if (dup2(fdout, 1) < 0)
		ft_error(6, NULL, NULL);
	close(fdout);
	redirect_gnl(av[2]);
	while (i < ac - 2)
	{
		redirect(av[i], 1, env);
		i++;
	}
	exec(av[i], env);
}

void	fds_check_and_dup(int *fdin, int *fdout)
{
	if (*fdin < 0)
		ft_error(5, NULL, NULL);
	if (*fdout < 0)
	{
		if (*fdin != 0)
			close(*fdin);
		ft_error(5, NULL, NULL);
	}
	if (*fdin != 0)
	{
		if (dup2(*fdin, 0) < 0)
			ft_error(6, NULL, NULL);
		close(*fdin);
	}
	if (dup2(*fdout, 1) < 0)
		ft_error(6, NULL, NULL);
	close(*fdout);
}
