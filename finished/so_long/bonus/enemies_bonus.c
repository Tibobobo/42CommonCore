/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:10 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/08 00:00:19 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

char	a_i_2(t_var *var)
{
	if (var->map.f2y > var->map.py && (var->map.f2y - var->map.py)
		> (var->map.f2x - var->map.px))
		return ('u');
	else if (var->map.f2x < var->map.px && (var->map.px - var->map.f2x)
		> (var->map.py - var->map.f2y))
		return ('r');
	else if (var->map.f2y < var->map.py && (var->map.py - var->map.f2y)
		> (var->map.px - var->map.f2x))
		return ('d');
	else if (var->map.f2x > var->map.px && (var->map.f2x - var->map.px)
		> (var->map.f2y - var->map.py))
		return ('l');
	else
		return (0);
}

char	a_i(t_var *var, int foe)
{
	if (foe == 1)
	{
		if (var->map.f1y > var->map.py && (var->map.f1y - var->map.py)
			> (var->map.f1x - var->map.px))
			return ('u');
		else if (var->map.f1x < var->map.px && (var->map.px - var->map.f1x)
			> (var->map.py - var->map.f1y))
			return ('r');
		else if (var->map.f1y < var->map.py && (var->map.py - var->map.f1y)
			> (var->map.px - var->map.f1x))
			return ('d');
		else if (var->map.f1x > var->map.px && (var->map.f1x - var->map.px)
			> (var->map.f1y - var->map.py))
			return ('l');
	}
	else
		return (a_i_2(var));
	return (0);
}

void	move_and_clean_2(t_var *var, char dir)
{
	var->map.grid[var->map.f2y][var->map.f2x] = '0';
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img,
		CELL_SIZE * var->map.f2x, CELL_SIZE * var->map.f2y);
	if (dir == 'u')
		var->map.f2y--;
	else if (dir == 'r')
		var->map.f2x++;
	else if (dir == 'd')
		var->map.f2y++;
	else if (dir == 'l')
		var->map.f2x--;
}

void	move_and_clean(t_var *var, int foe, char dir)
{
	if (foe == 1)
	{
		var->map.grid[var->map.f1y][var->map.f1x] = '0';
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img,
			CELL_SIZE * var->map.f1x, CELL_SIZE * var->map.f1y);
		if (dir == 'u')
			var->map.f1y--;
		else if (dir == 'r')
			var->map.f1x++;
		else if (dir == 'd')
			var->map.f1y++;
		else if (dir == 'l')
			var->map.f1x--;
	}
	else
		move_and_clean_2(var, dir);
}

void	place_enemies(t_var *var)
{
	if (var->foe_nb == 1 && var->frame < FRAME_LOOP / 3 && var->map.py >= 0)
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe1.mlx_img,
			var->map.f1x * CELL_SIZE, var->map.f1y * CELL_SIZE);
	else if (var->foe_nb == 1 && var->frame < FRAME_LOOP * 2 / 3
		&& var->map.py >= 0)
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe2.mlx_img,
			var->map.f1x * CELL_SIZE, var->map.f1y * CELL_SIZE);
	else if (var->foe_nb == 1 && var->frame <= FRAME_LOOP && var->map.py >= 0)
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe3.mlx_img,
			var->map.f1x * CELL_SIZE, var->map.f1y * CELL_SIZE);
	else if (var->foe_nb == 2)
		place_enemies_2(var);
}
