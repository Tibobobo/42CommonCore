/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:28:19 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/20 18:22:17 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

static int    up(t_map *map)
{
    if (map->grid[map->py - 1][map->px] != '1'
        && map->grid[map->py - 1][map->px] != 'V')
    {
        map->grid[map->py][map->px] = 'V';
        map->grid[map->py - 1][map->px] = 'P';
        map->py--;
            return (1);
    }
    return (0);
}

static int    right(t_map *map)
{
    if (map->grid[map->py][map->px + 1] != '1'
        && map->grid[map->py][map->px + 1] != 'V')
    {
        map->grid[map->py][map->px] = 'V';
        map->grid[map->py][map->px + 1] = 'P';
        map->px++;
            return (1);
    }
    return (0);
}

static int    down(t_map *map)
{
    if (map->grid[map->py + 1][map->px] != '1'
        && map->grid[map->py + 1][map->px] != 'V')
    {
        map->grid[map->py][map->px] = 'V';
        map->grid[map->py + 1][map->px] = 'P';
        map->py++;
            return (1);
    }
    return (0);
}

static int    left(t_map *map)
{
    if (map->grid[map->py][map->px - 1] != '1'
        && map->grid[map->py][map->px - 1] != 'V')
    {
        map->grid[map->py][map->px] = 'V';
        map->grid[map->py][map->px - 1] = 'P';
        map->px--;
            return (1);
    }
    return (0);
}

void    move(t_map *map, int dir)
{
    if (dir == 1)
        up(map);
    if (dir == 2)
        right(map);
    if (dir == 3)
        down(map);
    if (dir == 4)
        left(map);
}

int solve(t_map map)
{
    int d;
    
    d = 1;
    if (map.c == -1)
        return (1);
    while (d <= 4)
    {
        move(&map, d)
        d++;
    }
}