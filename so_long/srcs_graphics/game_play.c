/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:38:02 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/29 16:54:26 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int move_right(t_var *var)
{
    if (var->map.grid[var->map.py][var->map.px + 1] == '1')
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->p_r.mlx_img, var->map.px * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
    else
    {
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->p_r.mlx_img, (var->map.px + 1) * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img, var->map.px * CELL_SIZE, var->map.py * CELL_SIZE);
        var->map.px++;
        var->move++;
        ft_printf("You made %d moves.\n", var->move);
    }
    return (0);
}

int move_down(t_var *var)
{
    if (var->map.grid[var->map.py + 1][var->map.px] == '1')
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->p_d.mlx_img, var->map.px * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
    else
    {
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->p_d.mlx_img, var->map.px * CELL_SIZE + 10, (var->map.py + 1) * CELL_SIZE + 10);
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img, var->map.px * CELL_SIZE, var->map.py * CELL_SIZE);
        var->map.py++;
        var->move++;
        ft_printf("You made %d moves.\n", var->move);
    }
    return (0);
}

int move_left(t_var *var)
{
    if (var->map.grid[var->map.py][var->map.px - 1] == '1')
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->p_l.mlx_img, var->map.px * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
    else
    {
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->p_l.mlx_img, (var->map.px - 1) * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img, var->map.px * CELL_SIZE, var->map.py * CELL_SIZE);
        var->map.px--;
        var->move++;
        ft_printf("You made %d moves.\n", var->move);
    }
    return (0);
}

int move_up(t_var *var)
{
   if (var->map.grid[var->map.py - 1][var->map.px] == '1')
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->p_u.mlx_img, var->map.px * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
    else
    {
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->p_u.mlx_img, var->map.px * CELL_SIZE + 10, (var->map.py - 1) * CELL_SIZE + 10);
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img, var->map.px * CELL_SIZE, var->map.py * CELL_SIZE);
        var->map.py--;
        var->move++;
        ft_printf("You made %d moves.\n", var->move);
    }
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