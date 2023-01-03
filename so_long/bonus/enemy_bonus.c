/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:36:00 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/03 18:18:26 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

char    a_i(t_var *var, int foe)
{
    if (foe == 1)
    {
        if (var->map.f1y > var->map.py && (var->map.f1y - var->map.py) > (var->map.f1x - var->map.px))
            return ('u');
        else if (var->map.f1x < var->map.px && (var->map.px - var->map.f1x) > (var->map.py - var->map.f1y))
            return ('r');
        else if (var->map.f1y < var->map.py && (var->map.py - var->map.f1y) > (var->map.px - var->map.f1x))
            return ('d');
        else if (var->map.f1x > var->map.px && (var->map.f1x - var->map.px) > (var->map.f1y - var->map.py))
            return ('l');
    }
    else
    {
        if (var->map.f2y > var->map.py && (var->map.f2y - var->map.py) > (var->map.f2x - var->map.px))
            return ('u');
        else if (var->map.f2x < var->map.px && (var->map.px - var->map.f2x) > (var->map.py - var->map.f2y))
            return ('r');
        else if (var->map.f2y < var->map.py && (var->map.py - var->map.f2y) > (var->map.px - var->map.f2x))
            return ('d');
        else if (var->map.f2x > var->map.px && (var->map.f2x - var->map.px) > (var->map.f2y - var->map.py))
            return ('l');
    }
    return (0);
}

void    move_and_clean(t_var *var, int foe, char dir)
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
}

void    move_first(t_var *var)
{
    if (a_i(var, 1) == 'u' &&
        var->map.grid[var->map.f1y - 1][var->map.f1x] != '1' &&
        var->map.grid[var->map.f1y - 1][var->map.f1x] != 'C' &&
        var->map.grid[var->map.f1y - 1][var->map.f1x] != 'E')
        move_and_clean(var, 1, 'u');
    else if (a_i(var, 1) == 'r' &&
        var->map.grid[var->map.f1y][var->map.f1x + 1] != '1' &&
        var->map.grid[var->map.f1y][var->map.f1x + 1] != 'C' &&
        var->map.grid[var->map.f1y][var->map.f1x + 1] != 'E')
        move_and_clean(var, 1, 'r');
    else if (a_i(var, 1) == 'd' &&
        var->map.grid[var->map.f1y + 1][var->map.f1x] != '1' &&
        var->map.grid[var->map.f1y + 1][var->map.f1x] != 'C' &&
        var->map.grid[var->map.f1y + 1][var->map.f1x] != 'E') 
        move_and_clean(var, 1, 'd');
    else if (a_i(var, 1) == 'l' &&
        var->map.grid[var->map.f1y][var->map.f1x - 1] != '1' &&
        var->map.grid[var->map.f1y][var->map.f1x - 1] != 'C' &&
        var->map.grid[var->map.f1y][var->map.f1x - 1] != 'E')
        move_and_clean(var, 1, 'l');
}

void    move_second(t_var *var)
{
    if (a_i(var, 2) == 'u' &&
        var->map.grid[var->map.f2y - 1][var->map.f2x] != '1' &&
        var->map.grid[var->map.f2y - 1][var->map.f2x] != 'C' &&
        var->map.grid[var->map.f2y - 1][var->map.f2x] != 'E')
        move_and_clean(var, 2, 'u');
    else if (a_i(var, 2) == 'r' &&
        var->map.grid[var->map.f2y][var->map.f2x + 1] != '1' &&
        var->map.grid[var->map.f2y][var->map.f2x + 1] != 'C' &&
        var->map.grid[var->map.f2y][var->map.f2x + 1] != 'E')
        move_and_clean(var, 2, 'r');
    else if (a_i(var, 2) == 'd' &&
        var->map.grid[var->map.f2y + 1][var->map.f2x] != '1' &&
        var->map.grid[var->map.f2y + 1][var->map.f2x] != 'C' &&
        var->map.grid[var->map.f2y + 1][var->map.f2x] != 'E')
        move_and_clean(var, 2, 'd');
    else if (a_i(var, 2) == 'l' &&
        var->map.grid[var->map.f2y][var->map.f2x - 1] != '1' &&
        var->map.grid[var->map.f2y][var->map.f2x - 1] != 'C' &&
        var->map.grid[var->map.f2y][var->map.f2x - 1] != 'E')
        move_and_clean(var, 2, 'l');
}

void    move_enemy(t_var *var)
{
    if (var->map.f1y >= 0)
        move_first(var);
    if (var->map.f2y >=0)
        move_second(var);
}

void	position_2_foes(t_var *var, int i, int j)
{
	int	first;

	first = 0;
	while (var->map.grid[i] != NULL)
	{
		j = 0;
		while (var->map.grid[i][j] != '\0')
		{
			if (var->map.grid[i][j] == 'F' && first == 0)
			{
				var->map.f1x = j;
				var->map.f1y = i;
				first++;
			}
			if (var->map.grid[i][j] == 'F' && first == 1)
			{
				var->map.f2x = j;
				var->map.f2y = i;
			}
			j++;
		}
		i++;
	}
}

void	position_1_foe(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map.grid[i] != NULL)
	{
		j = 0;
		while (var->map.grid[i][j] != '\0')
		{
			if (var->map.grid[i][j] == 'F')
			{
				var->map.f1x = j;
				var->map.f1y = i;
			}
			j++;
		}
		i++;
	}
	var->map.f2x = -1000000000;
	var->map.f2y = -1000000000;
}

void    place_enemies(t_var *var)
{
    if (var->foe_nb == 1)
    {
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe.mlx_img,
				var->map.f1x * CELL_SIZE + 15, var->map.f1y * CELL_SIZE + 10);
    }
    else
    {
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe.mlx_img,
				var->map.f1x * CELL_SIZE + 15, var->map.f1y * CELL_SIZE + 10);
        mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->foe.mlx_img,
				var->map.f2x * CELL_SIZE + 15, var->map.f2y * CELL_SIZE + 10);
    }
}