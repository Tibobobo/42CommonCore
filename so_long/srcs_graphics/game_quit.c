/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:00:36 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/02 11:33:19 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void    leave_cell(t_var *var)
{
    if (var->item == 'c')
    {
        var->map.grid[var->map.py][var->map.px] = 'G';
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img, CELL_SIZE * var->map.px, CELL_SIZE * var->map.py);
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->g.mlx_img, CELL_SIZE * var->map.px + 10, CELL_SIZE * var->map.py + 10);
        var->item = ' ';
    }
    else if (var->item == 'e')
    {
        var->map.grid[var->map.py][var->map.px] = 'E';
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img, CELL_SIZE * var->map.px, CELL_SIZE * var->map.py);
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->e.mlx_img, CELL_SIZE * var->map.px + 10, CELL_SIZE * var->map.py + 10);
        var->item = ' ';
    }
    else
    {
        var->map.grid[var->map.py][var->map.px] = '0';
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img, CELL_SIZE * var->map.px, CELL_SIZE * var->map.py);
    }
}

void    mlx_error(t_var *var)
{
    if (var->mlx_ptr != NULL)
    {
        mlx_destroy_display(var->mlx_ptr);
        free(var->mlx_ptr);
    }
    free_map(var->map.grid);
    ft_putstr_fd("Error\nMLX couldn't render map\n", 2);
    exit (2);
}

int    game_quit(t_var *var)
{
    mlx_destroy_image(var->mlx_ptr, var->c.mlx_img);
    mlx_destroy_image(var->mlx_ptr, var->e.mlx_img);
    mlx_destroy_image(var->mlx_ptr, var->floor.mlx_img);
    mlx_destroy_image(var->mlx_ptr, var->p_d.mlx_img);
    mlx_destroy_image(var->mlx_ptr, var->p_u.mlx_img);
    mlx_destroy_image(var->mlx_ptr, var->p_l.mlx_img);
    mlx_destroy_image(var->mlx_ptr, var->p_r.mlx_img);
    mlx_destroy_image(var->mlx_ptr, var->wall.mlx_img);
    mlx_destroy_image(var->mlx_ptr, var->g.mlx_img);
    mlx_destroy_window(var->mlx_ptr, var->win_ptr);
    mlx_destroy_display(var->mlx_ptr);
    free_map(var->map.grid);
    free(var->mlx_ptr);
    exit (0);
}
