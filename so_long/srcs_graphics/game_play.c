/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:38:02 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/02 11:40:40 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int move_right(t_var *var)
{
    if (var->map.grid[var->map.py][var->map.px + 1] != '1')
    {
        leave_cell(var);
        if (var->map.grid[var->map.py][var->map.px + 1] == 'C')
        {
            var->map.c--;
            var->item = 'c';
        }
        else if (var->map.grid[var->map.py][var->map.px + 1] == 'E')
            var->item = 'e';
        else if (var->map.grid[var->map.py][var->map.px + 1] == 'G')
            var->item = 'c';
        var->map.grid[var->map.py][var->map.px + 1] = 'P';
        var->map.px++;
        var->move++;
        ft_printf("You made %d moves.\n", var->move);
    }
    var->dir = 'r';
    return (0);
}

int move_down(t_var *var)
{
    if (var->map.grid[var->map.py + 1][var->map.px] != '1')
    {
        leave_cell(var);
        if (var->map.grid[var->map.py + 1][var->map.px] == 'C')
        {
            var->map.c--;
            var->item = 'c';
        }
        else if (var->map.grid[var->map.py + 1][var->map.px] == 'E')
            var->item = 'e';
        else if (var->map.grid[var->map.py + 1][var->map.px] == 'G')
            var->item = 'c';
        var->map.grid[var->map.py + 1][var->map.px] = 'P';
        var->map.py++;
        var->move++;
        ft_printf("You made %d moves.\n", var->move);
    }
    var->dir = 'd';
    return (0);
}

int move_left(t_var *var)
{
    if (var->map.grid[var->map.py][var->map.px - 1] != '1')
    {
        leave_cell(var);
        if (var->map.grid[var->map.py][var->map.px - 1] == 'C')
        {
            var->map.c--;
            var->item = 'c';
        }
        else if (var->map.grid[var->map.py][var->map.px - 1] == 'E')
            var->item = 'e';
        else if (var->map.grid[var->map.py][var->map.px - 1] == 'G')
            var->item = 'c';
        var->map.grid[var->map.py][var->map.px - 1] = 'P';
        var->map.px--;
        var->move++;
        ft_printf("You made %d moves.\n", var->move);
    }
    var->dir = 'l';
    return (0);
}

int move_up(t_var *var)
{
    if (var->map.grid[var->map.py - 1][var->map.px] != '1')
    {
        leave_cell(var);
        if (var->map.grid[var->map.py - 1][var->map.px] == 'C')
        {
            var->map.c--;
            var->item = 'c';
        }
        else if (var->map.grid[var->map.py - 1][var->map.px] == 'E')
            var->item = 'e';
        else if (var->map.grid[var->map.py - 1][var->map.px] == 'G')
            var->item = 'c';
        var->map.grid[var->map.py - 1][var->map.px] = 'P';
        var->map.py--;
        var->move++;
        ft_printf("You made %d moves.\n", var->move);
    }
    var->dir = 'u';
    return (0);
}

int keypress(int key, t_var *var)
{
    if (key == 0xff1b)
        game_quit(var);
    else if (key == 0x0064)
        move_right(var);
    else if (key == 0x0073)
        move_down(var);
    else if (key == 0x0061)
        move_left(var);
    else if (key == 0x0077)
        move_up(var);
    return (0);
}