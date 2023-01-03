/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:38:02 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/03 11:29:16 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	leave_cell(t_var *var)
{
	if (var->item == 'c')
	{
		var->map.grid[var->map.py][var->map.px] = 'G';
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img,
			CELL_SIZE * var->map.px, CELL_SIZE * var->map.py);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->g.mlx_img,
			CELL_SIZE * var->map.px + 10, CELL_SIZE * var->map.py + 10);
		var->item = ' ';
	}
	else if (var->item == 'e')
	{
		var->map.grid[var->map.py][var->map.px] = 'E';
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img,
			CELL_SIZE * var->map.px, CELL_SIZE * var->map.py);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->e.mlx_img,
			CELL_SIZE * var->map.px, CELL_SIZE * var->map.py);
		var->item = ' ';
	}
	else
	{
		var->map.grid[var->map.py][var->map.px] = '0';
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->floor.mlx_img,
			CELL_SIZE * var->map.px, CELL_SIZE * var->map.py);
	}
}

int	move_right(t_var *var)
{
	if (var->map.grid[var->map.py][var->map.px + 1] != '1')
	{
		leave_cell(var);
		if (var->map.grid[var->map.py][var->map.px + 1] == 'C')
		{
			var->map.c--;
			var->item = 'c';
		}
		else if (var->map.grid[var->map.py][var->map.px + 1] == 'E')
			var->item = 'e';
		else if (var->map.grid[var->map.py][var->map.px + 1] == 'G')
			var->item = 'c';
		var->map.grid[var->map.py][var->map.px + 1] = 'P';
		var->map.px++;
		var->move++;
		display_moves(var);
	}
	var->dir = 'r';
	return (0);
}

int	move_down(t_var *var)
{
	if (var->map.grid[var->map.py + 1][var->map.px] != '1')
	{
		leave_cell(var);
		if (var->map.grid[var->map.py + 1][var->map.px] == 'C')
		{
			var->map.c--;
			var->item = 'c';
		}
		else if (var->map.grid[var->map.py + 1][var->map.px] == 'E')
			var->item = 'e';
		else if (var->map.grid[var->map.py + 1][var->map.px] == 'G')
			var->item = 'c';
		var->map.grid[var->map.py + 1][var->map.px] = 'P';
		var->map.py++;
		var->move++;
		display_moves(var);
	}
	var->dir = 'd';
	return (0);
}

int	move_left(t_var *var)
{
	if (var->map.grid[var->map.py][var->map.px - 1] != '1')
	{
		leave_cell(var);
		if (var->map.grid[var->map.py][var->map.px - 1] == 'C')
		{
			var->map.c--;
			var->item = 'c';
		}
		else if (var->map.grid[var->map.py][var->map.px - 1] == 'E')
			var->item = 'e';
		else if (var->map.grid[var->map.py][var->map.px - 1] == 'G')
			var->item = 'c';
		var->map.grid[var->map.py][var->map.px - 1] = 'P';
		var->map.px--;
		var->move++;
		display_moves(var);
	}
	var->dir = 'l';
	return (0);
}

int	move_up(t_var *var)
{
	if (var->map.grid[var->map.py - 1][var->map.px] != '1')
	{
		leave_cell(var);
		if (var->map.grid[var->map.py - 1][var->map.px] == 'C')
		{
			var->map.c--;
			var->item = 'c';
		}
		else if (var->map.grid[var->map.py - 1][var->map.px] == 'E')
			var->item = 'e';
		else if (var->map.grid[var->map.py - 1][var->map.px] == 'G')
			var->item = 'c';
		var->map.grid[var->map.py - 1][var->map.px] = 'P';
		var->map.py--;
		var->move++;
		display_moves(var);
	}
	var->dir = 'u';
	return (0);
}
