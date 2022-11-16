/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:46:15 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/16 16:52:54 by tgrasset         ###   ########.fr       */
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
		return (ft_strdup(""));
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
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr(storage, '\n') == NULL)
	{ 
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	if (bytes_read == 0 && buffer[0] == '\0')
		return (NULL);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = "";
	char		*next_line;
	char		test[5];

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, test, 0) == -1)
		return (NULL);
	storage = read_and_store(storage, fd);
	if (storage == NULL)
		return (NULL);
	next_line = extract_line(storage);
	storage = keep_remainder(storage);
	return (next_line);
}
