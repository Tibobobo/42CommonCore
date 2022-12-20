/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:06:53 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/20 16:13:53 by tgrasset         ###   ########.fr       */
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
	t_board	board;
	int		i;
	
	i = 0;
	map_pre_check(ac, av);
	board.map = parse_map(av[1]);
	if (board.map == NULL)
		ft_error(3);
	if (is_valid_map(&board) == 0)
	{
		free_map(board.map);
		ft_error(4);
	}
	while (board.map[i] != NULL)
	{
		ft_printf("%s\n", board.map[i]);
		i++;
	}
	ft_printf("%d\n%d\n%d\n", board.height, board.width, board.c);
	return (0);
}
