# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 10:44:30 by tgrasset          #+#    #+#              #
#    Updated: 2023/01/02 16:21:38 by tgrasset         ###   ########.fr        #
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

B_SRC	=	./bonus/info.c \

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

bonus: $(OBJS) $(B_OBJS) $(MLX_A) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(B_OBJS) ./libft/libft.a -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make fclean -C ./libft
	make clean -C ./minilibx-linux
	rm -f $(OBJS) $(B_OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus