/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:06:53 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/21 16:45:37 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "so_long.h"
#include "./libft/libft.h"

// TO_DO : Makefile relinks mlx
// 		Add enemies to allowed chars

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

int	main(int ac, char **av)
{
	t_var	var;

	var.map = full_check(ac, av, &var.map);
	return (0);
}
