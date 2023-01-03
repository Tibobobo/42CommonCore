# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 10:44:30 by tgrasset          #+#    #+#              #
#    Updated: 2023/01/03 10:51:18 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########### VARIABLES

SRCS	=	./main.c \
			./srcs_parsing/map_pre_check.c \
			./srcs_parsing/parse_map.c \
			./srcs_parsing/map_check.c \
			./srcs_parsing/is_solvable.c \
			./srcs_graphics/game_init.c \
			./srcs_graphics/game_quit.c \
			./srcs_graphics/game_play.c \

B_SRCS	=	./bonus/info_bonus.c \
			./bonus/game_init_bonus.c \
			./bonus/game_play_bonus.c \
			./bonus/game_quit_bonus.c \
			./bonus/is_solvable_bonus.c \
			./bonus/main_bonus.c \
			./bonus/map_pre_check_bonus.c \
			./bonus/parse_map_bonus.c \
			./bonus/map_check_bonus.c \

OBJS	=	$(SRCS:%.c=%.o)

B_OBJS	=	$(B_SRCS:%.c=%.o)

NAME	=	so_long

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

MLX_A	=	./minilibx-linux/libmlx_Linux.a

LIBFT_A	=	./libft/libft.a

###############################################################################
########### RULES

all:		$(NAME)

$(NAME):	$(OBJS) $(MLX_A) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(MLX_A):
	make -C ./minilibx-linux

$(LIBFT_A):
	make -C ./libft

bonus:		$(B_OBJS) $(MLX_A) $(LIBFT_A)
	$(CC) $(CFLAGS) $(B_OBJS) ./libft/libft.a -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make fclean -C ./libft
	make clean -C ./minilibx-linux
	rm -f $(OBJS) $(B_OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus