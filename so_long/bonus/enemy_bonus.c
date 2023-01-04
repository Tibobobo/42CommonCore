/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:36:00 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/04 10:47:14 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	move_first(t_var *var)
{
	if (a_i(var, 1) == 'u'
		&& var->map.grid[var->map.f1y - 1][var->map.f1x] != '1'
		&& var->map.grid[var->map.f1y - 1][var->map.f1x] != 'C'
		&& var->map.grid[var->map.f1y - 1][var->map.f1x] != 'E')
		move_and_clean(var, 1, 'u');
	else if (a_i(var, 1) == 'r'
		&& var->map.grid[var->map.f1y][var->map.f1x + 1] != '1'
		&&var->map.grid[var->map.f1y][var->map.f1x + 1] != 'C'
		&& var->map.grid[var->map.f1y][var->map.f1x + 1] != 'E')
		move_and_clean(var, 1, 'r');
	else if (a_i(var, 1) == 'd'
		&& var->map.grid[var->map.f1y + 1][var->map.f1x] != '1'
		&& var->map.grid[var->map.f1y + 1][var->map.f1x] != 'C'
		&& var->map.grid[var->map.f1y + 1][var->map.f1x] != 'E')
		move_and_clean(var, 1, 'd');
	else if (a_i(var, 1) == 'l'
		&& var->map.grid[var->map.f1y][var->map.f1x - 1] != '1'
		&& var->map.grid[var->map.f1y][var->map.f1x - 1] != 'C'
		&& var->map.grid[var->map.f1y][var->map.f1x - 1] != 'E')
		move_and_clean(var, 1, 'l');
}

void	move_second(t_var *var)
{
	if (a_i(var, 2) == 'u'
		&& var->map.grid[var->map.f2y - 1][var->map.f2x] != '1'
		&& var->map.grid[var->map.f2y - 1][var->map.f2x] != 'C'
		&& var->map.grid[var->map.f2y - 1][var->map.f2x] != 'E')
		move_and_clean(var, 2, 'u');
	else if (a_i(var, 2) == 'r'
		&& var->map.grid[var->map.f2y][var->map.f2x + 1] != '1'
		&& var->map.grid[var->map.f2y][var->map.f2x + 1] != 'C'
		&& var->map.grid[var->map.f2y][var->map.f2x + 1] != 'E')
		move_and_clean(var, 2, 'r');
	else if (a_i(var, 2) == 'd'
		&& var->map.grid[var->map.f2y + 1][var->map.f2x] != '1'
		&& var->map.grid[var->map.f2y + 1][var->map.f2x] != 'C'
		&& var->map.grid[var->map.f2y + 1][var->map.f2x] != 'E')
		move_and_clean(var, 2, 'd');
	else if (a_i(var, 2) == 'l'
		&& var->map.grid[var->map.f2y][var->map.f2x - 1] != '1'
		&& var->map.grid[var->map.f2y][var->map.f2x - 1] != 'C'
		&& var->map.grid[var->map.f2y][var->map.f2x - 1] != 'E')
		move_and_clean(var, 2, 'l');
}

void	move_enemy(t_var *var)
{
	if (var->map.f1y >= 0)
		move_first(var);
	if (var->map.f2y >= 0)
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
