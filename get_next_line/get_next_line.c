/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:46:15 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/16 11:30:53 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*keep_remainder(char *storage)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (storage[i] != '\0')
	{
		if (storage[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	if (storage[i] == '\0')
		return (NULL);
	remainder = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	while (storage[i] != '\0')
	{
		remainder[j] = storage[i];
		i++;
		j++;
	}
	remainder[j] = '\0';
	return (remainder);
}

char	*extract_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_and_store(char *storage, int fd)
{
	char	buffer[BUFFER_SIZE];

	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{ 
		buffer = read(fd, buffer, BUFFER_SIZE);
		storage = ft_strjoin(storage, buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			break;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*next_line;

	storage = read_and_store(storage, fd);
	next_line = extract_line(storage);
	storage = keep_remainder(storage);
	free(storage);
	return (next_line);
}
