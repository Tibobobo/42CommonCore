# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:53:18 by tgrasset          #+#    #+#              #
#    Updated: 2023/02/10 18:02:02 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########### VARIABLES

SRCS	=	./main.c \
			./arg_check.c \
			./utils.c \
			./init.c \
			./end.c \

OBJS	=	$(SRCS:%.c=%.o)

NAME	=	philo

CC		=	cc

CFLAGS	= 	-Wall -Wextra -Werror -pthread

###############################################################################
########### RULES

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re