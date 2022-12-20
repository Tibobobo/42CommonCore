# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 10:44:30 by tgrasset          #+#    #+#              #
#    Updated: 2022/12/20 12:07:23 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########### VARIABLES

SRCS	=	./main.c \
			./map_pre_check.c \
			./parse_map.c \
			./map_check.c \

OBJS	=	$(SRCS:%.c=%.o)

NAME	=	so_long

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

###############################################################################
########### RULES

all:		$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make fclean -C ./libft
	make clean -C ./minilibx-linux
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re