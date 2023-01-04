/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:52:07 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/04 17:14:14 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	render_background(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->map.height)
	{
		j = 0;
		while (j < var->map.width)
		{
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->floor.mlx_img, CELL_SIZE * j, CELL_SIZE * i);
			if (var->map.grid[i][j] == '1')
				mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
					var->wall.mlx_img, CELL_SIZE * j, CELL_SIZE * i);
			else if (var->map.grid[i][j] == 'E')
				mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
					var->e.mlx_img, j * CELL_SIZE, i * CELL_SIZE);
			else if (var->map.grid[i][j] == 'C')
				mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
					var->c.mlx_img, j * CELL_SIZE + 10, i * CELL_SIZE + 10);
			j++;
		}
		i++;
	}
}

int	game(t_var *var)
{
	check_win_or_lose(var);
	var->frame++;
	if (var->frame > FRAME_LOOP)
		var->frame = 0;
	animation(var);
	if (var->foe_nb != 0)
		place_enemies(var);
	return (0);
}

int	keypress(int key, t_var *var)
{
	if (key == 0xff1b)
		game_quit(var);
	else if (key == 0x0064 && var->map.py >= 0)
		move_right(var);
	else if (key == 0x0073 && var->map.py >= 0)
		move_down(var);
	else if (key == 0x0061 && var->map.py >= 0)
		move_left(var);
	else if (key == 0x0077 && var->map.py >= 0)
		move_up(var);
	return (0);
}

void	game_init(t_var *var)
{
	var->mlx_ptr = mlx_init();
	if (var->mlx_ptr == NULL)
		mlx_error(var);
	var->win_ptr = mlx_new_window(var->mlx_ptr, var->map.width * CELL_SIZE,
			var->map.height * CELL_SIZE, "so_long");
	if (var->win_ptr == NULL)
		mlx_error(var);
	load_sprites(var);
	render_background(var);
	var->frame = 0;
	mlx_loop_hook(var->mlx_ptr, game, var);
	mlx_hook(var->win_ptr, 2, 1L << 0, &keypress, var);
	mlx_hook(var->win_ptr, 17, 1L << 0, &game_quit, var);
	mlx_loop(var->mlx_ptr);
}
