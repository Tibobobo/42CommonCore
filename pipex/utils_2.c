/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:11:11 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/13 10:26:50 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
