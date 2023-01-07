/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:00:36 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/07 23:23:40 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

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

void	check_sprites(t_var *var)
{
	if (var->floor.mlx_img == NULL || var->c.mlx_img == NULL
		|| var->e.mlx_img == NULL || var->wall.mlx_img == NULL
		|| var->pd.mlx_img == NULL || var->pu.mlx_img == NULL
		|| var->pl.mlx_img == NULL || var->pr.mlx_img == NULL
		|| var->g.mlx_img == NULL)
	{
		ft_putstr_fd("Error while loading images.\n", 2);
		game_quit(var);
	}
}

int	game_quit(t_var *var)
{
	if (var->c.mlx_img != NULL)
		mlx_destroy_image(var->mlx_ptr, var->c.mlx_img);
	if (var->e.mlx_img != NULL)
		mlx_destroy_image(var->mlx_ptr, var->e.mlx_img);
	if (var->floor.mlx_img != NULL)
		mlx_destroy_image(var->mlx_ptr, var->floor.mlx_img);
	if (var->pd.mlx_img != NULL)
		mlx_destroy_image(var->mlx_ptr, var->pd.mlx_img);
	if (var->pu.mlx_img != NULL)
		mlx_destroy_image(var->mlx_ptr, var->pu.mlx_img);
	if (var->pl.mlx_img != NULL)
		mlx_destroy_image(var->mlx_ptr, var->pl.mlx_img);
	if (var->pr.mlx_img != NULL)
		mlx_destroy_image(var->mlx_ptr, var->pr.mlx_img);
	if (var->wall.mlx_img != NULL)
		mlx_destroy_image(var->mlx_ptr, var->wall.mlx_img);
	if (var->g.mlx_img != NULL)
		mlx_destroy_image(var->mlx_ptr, var->g.mlx_img);
	mlx_destroy_window(var->mlx_ptr, var->win_ptr);
	mlx_destroy_display(var->mlx_ptr);
	free_map(var->map.grid);
	free(var->mlx_ptr);
	exit (0);
}
