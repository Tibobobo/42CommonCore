/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:06:53 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/20 13:43:10 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "so_long.h"
#include "./libft/libft.h"

// TO_DO : Makefile relinks mlx
// 		Add enemies to allowed chars

int	main(int ac, char **av)
{
	// t_data	game;
	char	**map;
	int		i;
	
	i = 0;
	map_pre_check(ac, av);
	map = parse_map(av[1]);
	if (map == NULL)
		ft_error(3);
	if (is_valid_map(map) == 0)
	{
		free_map(map);
		ft_error(4);
	}
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	//TRUCS GRAPHIQUES
	return (0);
}
