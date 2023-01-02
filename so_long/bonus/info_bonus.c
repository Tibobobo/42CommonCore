/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:13:52 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/02 18:24:56 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void    draw_info_box(t_var *var)
{
    int i;
    int j;
    
    var->info.mlx_img = mlx_new_image(var->mlx_ptr, CELL_SIZE * var->map.width, 15);
    var->info.addr = mlx_get_data_addr(var->info.mlx_img, &var->info.bpp, &var->info.line_len, &var->info.endian);
    i = 0;
    while (i < 15)
    {
        j = 0;
        while (j < CELL_SIZE * var->map.width)
        {
            img_pix_put(&var->info, i, j, 0xFFFFFF);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->info.mlx_img, 0, 0);
}

void    display_info(t_var *var)   //COMPILE PAS ENCORE
{
    char    *info;

    info = ft_itoa(var->move);
    draw_info_box(var);
    mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 5, 0xFF0000, info);
}