/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:00:36 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/03 12:52:03 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	check_win_or_lose(t_var *var)
{
	if (var->map.c == 0 && var->item == 'e')
	{
		ft_printf("Well done, level cleared !\n");
		game_quit(var);
	}
	if ((var->map.px == var->map.f1x && var->map.py == var->map.f1y)
		|| (var->map.px == var->map.f2x && var->map.py == var->map.f2y))
	{
		ft_printf("You lost :( \n");
		game_quit(var);
	}
}

void	mlx_error(t_var *var)
{
	if (var->mlx_ptr != NULL)
	{
		mlx_destroy_display(var->mlx_ptr);
		free(var->mlx_ptr);
	}
	free_map(var->map.grid);
	ft_putstr_fd("Error\nMLX couldn't render map\n", 2);
	exit (2);
}

int	game_quit(t_var *var)
{
	mlx_destroy_image(var->mlx_ptr, var->c.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->e.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->floor.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pd.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pu.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pl.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pr.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->wall.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->g.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->info.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->foe.mlx_img);
	mlx_destroy_window(var->mlx_ptr, var->win_ptr);
	mlx_destroy_display(var->mlx_ptr);
	free_map(var->map.grid);
	free(var->mlx_ptr);
	exit (0);
}
