/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:52:07 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/28 17:35:49 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

// void    draw_sprite(t_img *scr, t_img *sprite, int y, int x)
// {
    
// }

int render_background(t_var *var)
{
    int i;
    int j;
    
    var->scr.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/floor.xpm", &var->map.width, &var->map.height);
    i = 0;
    while (i < CELL_SIZE * var->map.height)
    {
        j = 0;
        while (j < CELL_SIZE * var->map.width)
        {
            mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->scr.mlx_img, j, i);
            j += CELL_SIZE;
        }
        i += CELL_SIZE;
    }
    
    return (0);
}

void    load_sprites(t_var *var, t_sprites *sprites)
{
    int width;
    int height;

    width = CELL_SIZE;     //OSEF ?
    height = CELL_SIZE;
    sprites->floor.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, ".sprites/floor.xpm", &width, &height);
    sprites->c.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/chest.xpm", &width, &height);
    sprites->e.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/chest.xpm", &width, &height);
    sprites->wall.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/tree.xpm", &width, &height);
    sprites->p.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr, "./sprites/player_down.xpm", &width, &height);
}

void    level_init(t_var *var, t_sprites *sprites)
{
    int i;
    int j;

    load_sprites(var, sprites);
    i = 0;
    while (var->map.grid[i] != NULL)
    {
        j = 0;
        while (var->map.grid[i][j] != '\0')
        {
            if (var->map.grid[i][j] == '1')
                // draw_sprite(&var->scr, &sprites->wall, i, j);
                mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, sprites->wall.mlx_img, j * CELL_SIZE, i * CELL_SIZE);
            else if (var->map.grid[i][j] == 'P')
                // draw_sprite(&var->scr, &sprites->p, i, j);
                mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, sprites->p.mlx_img, j * CELL_SIZE + 10 , i * CELL_SIZE + 10);
            // else if (var->map.grid[i][j] == 'E')
            //     render_exit(var, i, j);
            else if (var->map.grid[i][j] == 'C')
                // draw_sprite(&var->scr, &sprites->c, i, j);
                 mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, sprites->c.mlx_img, j * CELL_SIZE + 10, i * CELL_SIZE + 10);
            j++;
        }
        i++;
    }
    // mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->scr.mlx_img, 0, 0);
}

void    game_init(t_var *var)
{
    t_sprites   sprites;
    
    var->mlx_ptr = mlx_init();
    if (var->mlx_ptr == NULL)
        mlx_error(var);
    var->win_ptr = mlx_new_window(var->mlx_ptr, var->map.width * CELL_SIZE,
        var->map.height * CELL_SIZE, "so_long");
    if (var->win_ptr == NULL)
        mlx_error(var);
    render_background(var);
    level_init(var, &sprites);
    // mlx_loop_hook(var->mlx_ptr, game, var);
    mlx_hook(var->win_ptr, 2, 1L<<0, &keypress, &var);
    mlx_loop(var->mlx_ptr);
}