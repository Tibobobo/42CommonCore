/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:29:27 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/21 11:43:48 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

char	**free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

static char	**fill_map(char **map, char *path, int height)
{
	int	i;
	int	fd;

	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free_map(map));
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			return (free_map(map));
		i++;
	}
	map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

static char	**clean_nl(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		j--;
		if (map[i][j] == '\n')
			map[i][j] = '\0';
		i++;
	}
	return (map);
}

char	**parse_map(char *path)
{
	int		fd;
	int		height;
	char	**map;
	char	*line;

	height = 0;
	map = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	while (line != NULL)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	map = fill_map(map, path, height);
	if (map == NULL)
		return (NULL);
	return (clean_nl(map));
}
