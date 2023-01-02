/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:19:40 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/02 11:28:29 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int		width;
	int		height;
	int		px;
	int		py;
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
	t_img	scr;
	t_img	floor;
	t_img	wall;
	t_img	e;
	t_img	c;
	t_img	p_d;
	t_img	p_r;
	t_img	p_l;
	t_img	p_u;
	t_img	g;
	int		move;
	char	dir;
	char	item;
}				t_var;

void	map_pre_check(int ac, char **av);
char	**parse_map(char *path);
void	ft_error(int num);
char	**free_map(char **map);
int		is_valid_map(t_map *map);
void	solve(t_map map, char *path, int vx, int vy);
void    game_init(t_var *var);
int		game_quit(t_var *var);
void    mlx_error(t_var *var);
int		keypress(int key, t_var *var);
void    leave_cell(t_var *var);

#endif
