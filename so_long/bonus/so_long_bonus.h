/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:19:40 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/07 23:37:21 by tgrasset         ###   ########.fr       */
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
# define FRAME_LOOP 21000

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
	t_img	pd1;
	t_img	pd2;
	t_img	pr1;
	t_img	pr2;
	t_img	pl1;
	t_img	pl2;
	t_img	pu1;
	t_img	pu2;
	t_img	g;
	t_img	info;
	t_img	foe1;
	t_img	foe2;
	t_img	foe3;
	t_img	dead;
	int		move;
	char	dir;
	char	item;
	int		foe_nb;
	int		frame;
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
void	display_moves(t_var *var);
void	position_2_foes(t_var *var, int i, int j);
void	position_1_foe(t_var *var);
void	place_enemies(t_var *var);
void	check_win_or_lose(t_var *var);
void	move_enemy(t_var *var);
char	a_i(t_var *var, int foe);
void	move_and_clean(t_var *var, int foe, char dir);
void	animation(t_var *var);
void	load_sprites(t_var *var);
void	place_enemies_2(t_var *var);

#endif
