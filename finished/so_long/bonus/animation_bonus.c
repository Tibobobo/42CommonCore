/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:32:57 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/07 23:53:02 by tgrasset         ###   ########.fr       */
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
	if (var->frame < FRAME_LOOP / 3 && var->map.py >= 0)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe1.mlx_img,
			var->map.f1x * CELL_SIZE, var->map.f1y * CELL_SIZE);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe2.mlx_img,
			var->map.f2x * CELL_SIZE, var->map.f2y * CELL_SIZE);
	}
	else if (var->frame < FRAME_LOOP * 2 / 3 && var->map.py >= 0)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe2.mlx_img,
			var->map.f1x * CELL_SIZE, var->map.f1y * CELL_SIZE);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe3.mlx_img,
			var->map.f2x * CELL_SIZE, var->map.f2y * CELL_SIZE);
	}
	else if (var->frame < FRAME_LOOP && var->map.py >= 0)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe3.mlx_img,
			var->map.f1x * CELL_SIZE, var->map.f1y * CELL_SIZE);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe1.mlx_img,
			var->map.f2x * CELL_SIZE, var->map.f2y * CELL_SIZE);
	}
}

void	load_sprites_2(t_var *var)
{
	var->pr1.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/pr1.xpm", &var->pr1.w, &var->pr1.h);
	var->pr2.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/pr2.xpm", &var->pr2.w, &var->pr2.h);
	var->g.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/o_chest.xpm", &var->g.w, &var->g.h);
	var->info.mlx_img = mlx_new_image(var->mlx_ptr,
			CELL_SIZE * var->map.width, 15);
	var->foe1.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/foe1.xpm", &var->foe1.w, &var->foe1.h);
	var->foe2.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/foe2.xpm", &var->foe2.w, &var->foe2.h);
	var->foe3.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/foe3.xpm", &var->foe3.w, &var->foe3.h);
	var->dead.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/dead.xpm", &var->dead.w, &var->dead.h);
}

void	load_sprites(t_var *var)
{
	var->dir = 'd';
	var->move = 0;
	var->item = ' ';
	var->floor.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/floor.xpm", &var->floor.w, &var->floor.h);
	var->c.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/chest.xpm", &var->c.w, &var->c.h);
	var->e.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/exit.xpm", &var->e.w, &var->e.h);
	var->wall.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/tree.xpm", &var->wall.w, &var->wall.h);
	var->pd1.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/pd1.xpm", &var->pd1.w, &var->pd1.h);
	var->pd2.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/pd2.xpm", &var->pd2.w, &var->pd2.h);
	var->pu1.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/pu1.xpm", &var->pu1.w, &var->pu1.h);
	var->pu2.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/pu2.xpm", &var->pu2.w, &var->pu2.h);
	var->pl1.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/pl1.xpm", &var->pl1.w, &var->pl1.h);
	var->pl2.mlx_img = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/pl2.xpm", &var->pl2.w, &var->pl2.h);
	load_sprites_2(var);
}
