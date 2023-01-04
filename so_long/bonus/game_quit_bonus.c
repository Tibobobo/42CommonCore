/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:00:36 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/04 17:17:01 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	check_win_or_lose(t_var *var)
{
	if (var->map.c == 0 && var->item == 'e')
	{
		var->map.py = -1;
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->info.mlx_img, 0, 0);
		mlx_string_put(var->mlx_ptr, var->win_ptr, 30, 11, 0x509B66,
			"Well done ! You cleared the level. Press ESC to quit.");
	}
	if ((var->map.px == var->map.f1x && var->map.py == var->map.f1y)
		|| (var->map.px == var->map.f2x && var->map.py == var->map.f2y))
	{
		var->map.py = -1;
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->info.mlx_img, 0, 0);
		mlx_string_put(var->mlx_ptr, var->win_ptr, 30, 11, 0xFF0000,
			"You lost :( Press ESC to quit.");
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
	mlx_destroy_image(var->mlx_ptr, var->pd1.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pd2.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pu1.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pu2.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pl1.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pl2.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pr1.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->pr2.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->wall.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->g.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->info.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->foe1.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->foe2.mlx_img);
	mlx_destroy_image(var->mlx_ptr, var->foe3.mlx_img);
	mlx_destroy_window(var->mlx_ptr, var->win_ptr);
	mlx_destroy_display(var->mlx_ptr);
	free_map(var->map.grid);
	free(var->mlx_ptr);
	exit (0);
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
