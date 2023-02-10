/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:20:53 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/10 22:23:07 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	remainder_length(char *str, int end)
{
	int	i;
	int	j;

	i = end;
	j = 0;
	while (str[end] != '\0')
	{
		end++;
		j++;
	}
	return (j);
}
