/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:00:36 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/29 16:58:57 by tgrasset         ###   ########.fr       */
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
    mlx_destroy_window(var->mlx_ptr, var->win_ptr);
    mlx_destroy_display(var->mlx_ptr);
    free_map(var->map.grid);
    free(var->mlx_ptr);
    exit (0);
}
