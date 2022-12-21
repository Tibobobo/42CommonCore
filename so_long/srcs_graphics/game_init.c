/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:52:07 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/21 18:54:38 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void    mlx_error(t_var *var)
{
    if (var->mlx_ptr != NULL)
    {
        mlx_destroy_display(var->mlx_ptr);
        free(var->mlx_ptr);
    }
    free(var->map.grid);
    ft_putstr_fd("Error\nMLX couldn't render map\n", 2);
    exit (2);
}

void    img_pix_put(t_var *var, int x, int y, int color)
{
    char    *pix;
	
    ft_printf("DEBUG\n");
    pix = var->img.addr + (y * var->img.line_len + x * (var->img.bpp / 8));
    ft_printf("DEBUG\n");
    *(unsigned int *)pix = color;    //SEGFAUUUUULT 
    ft_printf("DEBUG\n");
}

void    render_background(t_var *var, int color)
{
    int i;
    int j;

    i = 0;
    while (i < CELL_SIZE * var->map.height)
    {
        j = 0;
        while (j < CELL_SIZE * var->map.width)
        {
            img_pix_put(var, j, i, color);
            j++;
        }
        i++;
    }
}

int display(t_var *var)
{
    if (var->win_ptr == NULL)
        return (1);
    render_background(var, 0x00FF00);
    mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img.mlx_img, 0, 0);
    return (0);
}

void    game_init(t_var *var)
{
    var->mlx_ptr = mlx_init();
    if (var->mlx_ptr == NULL)
        mlx_error(var);
    var->win_ptr = mlx_new_window(var->mlx_ptr, var->map.width * CELL_SIZE,
        var->map.height * CELL_SIZE, "so_long");
    if (var->win_ptr == NULL)
        mlx_error(var);
    var->img.mlx_img = mlx_new_image(var->mlx_ptr, var->map.width * CELL_SIZE,
        var->map.height * CELL_SIZE);
    var->img.addr = mlx_get_data_addr(&var->img.mlx_img, &var->img.bpp,
        &var->img.line_len, &var->img.endian);
    display(var);
    mlx_loop(var->mlx_ptr);
}