/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:46:15 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/14 18:01:08 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[BUFFER_SIZE];
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	read(fd, buffer, BUFFER_SIZE);
}
