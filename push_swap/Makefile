# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 10:44:30 by tgrasset          #+#    #+#              #
#    Updated: 2022/12/12 10:35:15 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########### VARIABLES

SRCS	=	./main.c \
			./ft_atol.c \
			./arg_check.c \
			./push_actions.c \
			./r_rotate_actions.c \
			./rotate_actions.c \
			./stack_stuff.c \
			./stack_stuff_2.c \
			./stack_stuff_3.c \
			./swap_actions.c \
			./sort.c \
			
OBJS	=	$(SRCS:%.c=%.o)

NAME	=	push_swap

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

###############################################################################
########### RULES

all:		$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re
