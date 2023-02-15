/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:33:56 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/15 20:43:01 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_last_redir(t_redir *redir)
{
	t_redir	*temp;

	temp = redir->next;
	while (temp != NULL)
	{
		if (temp->output == redir->output)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_if_empty_str(char *str)
{
	if (str != NULL && str[0] == '\0')
	{
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	return (0);
}
