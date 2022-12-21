/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:28:19 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/21 10:49:31 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

// static int    up(t_map *map)
// {
//     if (map->grid[map->py - 1][map->px] != '1'
//         && map->grid[map->py - 1][map->px] != 'V')
//     {
//         map->grid[map->py][map->px] = 'V';
//         map->grid[map->py - 1][map->px] = 'P';
//         map->py--;
//             return (1);
//     }
//     return (0);
// }

// static int    right(t_map *map)
// {
//     if (map->grid[map->py][map->px + 1] != '1'
//         && map->grid[map->py][map->px + 1] != 'V')
//     {
//         map->grid[map->py][map->px] = 'V';
//         map->grid[map->py][map->px + 1] = 'P';
//         map->px++;
//             return (1);
//     }
//     return (0);
// }

// static int    down(t_map *map)
// {
//     if (map->grid[map->py + 1][map->px] != '1'
//         && map->grid[map->py + 1][map->px] != 'V')
//     {
//         map->grid[map->py][map->px] = 'V';
//         map->grid[map->py + 1][map->px] = 'P';
//         map->py++;
//             return (1);
//     }
//     return (0);
// }

// static int    left(t_map *map)
// {
//     if (map->grid[map->py][map->px - 1] != '1'
//         && map->grid[map->py][map->px - 1] != 'V')
//     {
//         map->grid[map->py][map->px] = 'V';
//         map->grid[map->py][map->px - 1] = 'P';
//         map->px--;
//             return (1);
//     }
//     return (0);
// }

// void    move(t_map *map, int dir)
// {
//     if (dir == 1)
//         up(map);
//     if (dir == 2)
//         right(map);
//     if (dir == 3)
//         down(map);
//     if (dir == 4)
//         left(map);
// }

static void    new_move(t_find **head, int x, int y)
{
    t_find *new;

    new = malloc(sizeof(t_find));
    if (new == NULL)
        return;
    new->x = x;
    new->y = y;
    new ->prev = NULL;
    if (!head || !(*head))
        *head = new;
    else
    {
        new->prev = *head;
        *head = new;
    }
}

static void    free_solve(t_find **head, char **copy)
{
    t_find  *temp;

    while ((*head)->prev != NULL)
    {
        temp = *head;
        *head = (*head)->prev;
        free(temp);
    }
    free(*head);
    free_map(copy);
}

void solve(t_map map, char *path, int vx, int vy)
{
    t_find  *move;
    t_find  *temp;
    int     c;
    char    **copy;
    
    copy = parse_map(path);
    if (copy == NULL)
    {
        free_map(map.grid);
        ft_error(3);
    }
    move = NULL;
    c = map.c;
    new_move(&move, vx, vy);
    while (move != NULL)
    {
        if (copy[vy][vx] == 'C' || copy[vy][vx] == 'E')
            c--;
        if (c == -1)
        {
            free_solve(&move, copy);
            return ;
        }
        copy[vy][vx] = 'S';
        if (copy[vy][vx + 1] != '1' && copy[vy][vx + 1] != 'S')
            new_move(&move, ++vx, vy);
        else if (copy[vy + 1][vx] != '1' && copy[vy + 1][vx] != 'S')
            new_move(&move, vx, ++vy);
        else if (copy[vy][vx - 1] != '1' && copy[vy][vx - 1] != 'S' )
            new_move(&move, --vx, vy);
        else if (copy[vy - 1][vx] != '1' && copy[vy - 1][vx] != 'S')
            new_move(&move, vx, --vy);
        else
        {
            if (move->prev == NULL)
            {
                free_solve(&move, copy);
                free_map(map.grid);
                ft_error(5);
            }
            temp = move;
            move = move->prev;
            free(temp);
            vy = move->y;
            vx = move->x;
        }
    }
}