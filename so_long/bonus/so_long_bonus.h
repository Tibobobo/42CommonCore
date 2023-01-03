/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:19:40 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/03 13:46:28 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define CELL_SIZE 50

typedef struct s_map
{
	char	**grid;
	int		c;
	int		c_total;
	int		width;
	int		height;
	int		px;
	int		py;
	int		f1x;
	int		f1y;
	int		f2x;
	int		f2y;
}				t_map;

typedef struct s_find
{
	struct s_find	*prev;
	int				x;
	int				y;
}				t_find;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}				t_img;

typedef struct s_var
{
	t_map	map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	floor;
	t_img	wall;
	t_img	e;
	t_img	c;
	t_img	pd;
	t_img	pr;
	t_img	pl;
	t_img	pu;
	t_img	g;
	t_img	info;
	t_img	foe;
	int		move;
	char	dir;
	char	item;
	int		foe_nb;
}				t_var;

void	map_pre_check(int ac, char **av);
char	**parse_map(char *path);
void	ft_error(int num);
char	**free_map(char **map);
int		is_valid_map(t_map *map);
void	solve(t_map map, char *path, int vx, int vy);
void	game_init(t_var *var);
int		game_quit(t_var *var);
void	mlx_error(t_var *var);
int		keypress(int key, t_var *var);
void	leave_cell(t_var *var);
int		move_up(t_var *var);
int		move_left(t_var *var);
int		move_down(t_var *var);
int		move_right(t_var *var);
void    display_moves(t_var *var);
void	position_2_foes(t_var *var, int i, int j);
void	position_1_foe(t_var *var);
void    place_enemies(t_var *var);
void	check_win_or_lose(t_var *var);
void	move_enemy(t_var *var);

#endif
