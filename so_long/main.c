/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:06:53 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/02 14:34:03 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "so_long.h"
#include "./libft/libft.h"

static t_map	full_check(int ac, char **av, t_map *map)
{
	map_pre_check(ac, av);
	map->grid = parse_map(av[1]);
	if (map->grid == NULL)
		ft_error(3);
	if (is_valid_map(map) == 0)
	{
		free_map(map->grid);
		ft_error(4);
	}
	solve(*map, av[1], map->px, map->py);
	return (*map);
}

void	launch_game(t_var *var)
{
	game_init(var);
	game_quit(var);
}

int	main(int ac, char **av)
{
	t_var	var;

	var.map = full_check(ac, av, &var.map);
	launch_game(&var);
	return (0);
}
