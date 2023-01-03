/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:06:53 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/03 13:28:14 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long_bonus.h"
#include "../libft/libft.h"

int	check_foe_nb(char **grid)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while(grid[i] != NULL)
	{
		j = 0;
		while(grid[i][j] != '\0')
		{
			if (grid[i][j] == 'F')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

void	assign_foe_position(t_var *var)
{
	if (var->foe_nb == 0)
	{
		var->map.f1x = -1000000000;
		var->map.f1y = -1000000000;
		var->map.f2x = -1000000000;
		var->map.f2y = -1000000000;
		return ;
	}
	else if (var->foe_nb == 1)
		position_1_foe(var);
	else if (var->foe_nb == 2)
		position_2_foes(var, 0, 0);
}

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
	var.foe_nb = check_foe_nb(var.map.grid);
	if (var.foe_nb > 2)
	{
		free_map(var.map.grid);
		ft_putstr_fd("Too many enemies, maximum is 2\n", 2);
		return (-1);
	}
	assign_foe_position(&var);
	game_init(&var);
	return (0);
}
