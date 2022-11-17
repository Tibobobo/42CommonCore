/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:46:15 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/17 19:06:29 by tgrasset         ###   ########.fr       */
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
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	i++;
	remainder = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!remainder)
		return (NULL);
	while (storage[i] != '\0')
	{
		remainder[j] = storage[i];
		i++;
		j++;
	}
	remainder[j] = '\0';
	free(storage);
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
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read != 0 && ft_strchr(storage, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		storage = join_and_free(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*join_and_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(""));
	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	storage = read_and_store(storage, fd);
	if (storage == NULL)
		return (NULL);
	next_line = extract_line(storage);
	storage = keep_remainder(storage);
	return (next_line);
}
