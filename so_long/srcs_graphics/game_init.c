/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:52:07 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/29 17:05:42 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void    render_background(t_var *var)
{
    int i;
    int j;
    
    i = 0;
    while (i < var->map.height)
    {
        j = 0;
        while (j < var->map.width)
        {
            mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img, CELL_SIZE * j, CELL_SIZE * i);
            if (var->map.grid[i][j] == '1')
                mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->wall.mlx_img, CELL_SIZE * j, CELL_SIZE * i);
            j ++;
        }
        i ++;
    }
}

void    load_sprites(t_var *var)
{
    var->dir = 'd';
    var->move = 0;
    var->floor.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/floor.xpm", &var->floor.w, &var->floor.h);
    var->c.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/chest.xpm", &var->c.w, &var->c.h);
    var->e.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/o_chest.xpm", &var->e.w, &var->e.h);
    var->wall.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/tree.xpm", &var->wall.w, &var->wall.h);
    var->p_d.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/player_down.xpm", &var->p_d.w, &var->p_d.h);
    var->p_u.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/player_down.xpm", &var->p_u.w, &var->p_u.h);
    var->p_l.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/player_left.xpm", &var->p_l.w, &var->p_l.h);
    var->p_r.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/player_right.xpm", &var->p_r.w, &var->p_r.h);
}

int    game(t_var *var)
{
    int i;
    int j;

    i = 0;
    while (var->map.grid[i] != NULL)
    {
        j = 0;
        while (var->map.grid[i][j] != '\0')
        {
            if (var->map.grid[i][j] == 'P')
                // mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->p_d.mlx_img, j * CELL_SIZE + 10 , i * CELL_SIZE + 10);
            else if (var->map.grid[i][j] == 'E')
                mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->e.mlx_img, j * CELL_SIZE + 10, i * CELL_SIZE + 10);
            else if (var->map.grid[i][j] == 'C')
                mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->c.mlx_img, j * CELL_SIZE + 10, i * CELL_SIZE + 10);
            else if (var->map.grid[i][j] == 'G')
            j++;
        }
        i++;
    }
    return (0);
    // mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->scr.mlx_img, 0, 0);
}

void    game_init(t_var *var)
{
    var->mlx_ptr = mlx_init();
    if (var->mlx_ptr == NULL)
        mlx_error(var);
    var->win_ptr = mlx_new_window(var->mlx_ptr, var->map.width * CELL_SIZE, var->map.height * CELL_SIZE, "so_long");
    if (var->win_ptr == NULL)
        mlx_error(var);
    load_sprites(var);
    render_background(var);
    mlx_loop_hook(var->mlx_ptr, game, var);
    mlx_hook(var->win_ptr, 2, 1L<<0, &keypress, var);
    mlx_loop(var->mlx_ptr);
}