/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:54:55 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/20 16:12:46 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

static int  is_rectangular(char **map)
{
    size_t len;
    int i;

    i = 0;
    len = ft_strlen(map[i]);
    while (map[i] != NULL)
    {
        if (ft_strlen(map[i]) != len)
            return (0);
        i++;
    }
    return (1);
}

static int  char_check(char **map, int i, int c, int e, int p)
{
    int j;
    
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')      //ajouter ennemis pour bonus
        {
            if  (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
                && map[i][j] != 'E' && map[i][j] != 'P')
                return (0);
            if (map[i][j] == 'C')
                c++;
            else if (map[i][j] == 'E')
                e++;
            else if (map[i][j] == 'P')
                p++;
            j++;
        }
        i++;
    }
    if (c == 0 || e == 0 || e > 1 || p == 0 || p > 1)
        return (0);
    return (1);
}

static int  is_closed(char **map, int i, int width, int height, int j)
{
    width = ft_strlen(map[0]);
    while (map[height] != NULL)
        height++;
    while (map[0][j] != '\0' && map[height - 1][j] != '\0')
    {
        if (map[0][j] != '1' || map[height - 1][j] != '1')
            return (0);
        j++;
    }
    while (map[i + 1] != NULL)
    {
        if (map[i][0] != '1' || map[i][width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

static void assign_values(t_board *board, int i, int j, int c)
{
    board->width = ft_strlen(board->map[0]);
    while (board->map[i] != NULL)
        i++;
    board->height = i;
    i = 0;
    while (board->map[i] != NULL)
    {
        j = 0;
        while (board->map[i][j] != '\0')
        {
            if (board->map[i][j] == 'C')
                c++;
            j++;
        }
        i++;
    }
    board->c = c;
}

int is_valid_map(t_board *board)
{
    if (is_rectangular(board->map) == 0)
        return (0);
    if (char_check(board->map, 0, 0, 0, 0) == 0)
        return (0);
    if (is_closed(board->map, 0, 0, 0, 0) == 0)
        return (0);
    assign_values(board, 0, 0, 0);
    // if (is_possible(board) == 0)
    //     return (0);
    return (1);
}