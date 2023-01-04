/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:32:57 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/04 17:34:11 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	animation_2(t_var *var)
{
	if (var->dir == 'd')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->pd2.mlx_img,
			var->map.px * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
	else if (var->dir == 'u')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->pu2.mlx_img,
			var->map.px * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
	else if (var->dir == 'r')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->pr2.mlx_img,
			var->map.px * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
	else if (var->dir == 'l')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->pl2.mlx_img,
			var->map.px * CELL_SIZE + 10, var->map.py * CELL_SIZE + 10);
}

void	animation(t_var *var)
{
	if (var->frame > FRAME_LOOP / 2)
	{
		if (var->dir == 'd')
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->pd1.mlx_img, var->map.px * CELL_SIZE + 10,
				var->map.py * CELL_SIZE + 10);
		else if (var->dir == 'u')
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->pu1.mlx_img, var->map.px * CELL_SIZE + 10,
				var->map.py * CELL_SIZE + 10);
		else if (var->dir == 'r')
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->pr1.mlx_img, var->map.px * CELL_SIZE + 10,
				var->map.py * CELL_SIZE + 10);
		else if (var->dir == 'l')
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->pl1.mlx_img, var->map.px * CELL_SIZE + 10,
				var->map.py * CELL_SIZE + 10);
	}
	else
		animation_2(var);
}

void	place_enemies_2(t_var *var)
{
	if (var->frame < FRAME_LOOP / 3)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe1.mlx_img,
			var->map.f1x * CELL_SIZE, var->map.f1y * CELL_SIZE);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe2.mlx_img,
			var->map.f2x * CELL_SIZE, var->map.f2y * CELL_SIZE);
	}
	else if (var->frame < FRAME_LOOP * 2 / 3)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe2.mlx_img,
			var->map.f1x * CELL_SIZE, var->map.f1y * CELL_SIZE);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe3.mlx_img,
			var->map.f2x * CELL_SIZE, var->map.f2y * CELL_SIZE);
	}
	else if (var->frame < FRAME_LOOP)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe3.mlx_img,
			var->map.f1x * CELL_SIZE, var->map.f1y * CELL_SIZE);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe1.mlx_img,
			var->map.f2x * CELL_SIZE, var->map.f2y * CELL_SIZE);
	}
}
