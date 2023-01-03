/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:36:00 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/03 12:35:17 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

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
	var->map.f2x = 0;
	var->map.f2x = 0;
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