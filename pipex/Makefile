# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 09:47:26 by tgrasset          #+#    #+#              #
#    Updated: 2023/01/11 12:21:19 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########### VARIABLES

SRCS	=	./main.c \
			./utils.c \

B_SRCS	=	./bonus/main_bonus.c \
			./bonus/utils_bonus.c \

OBJS	=	$(SRCS:%.c=%.o)

B_OBJS	=	$(B_SRCS:%.c=%.o)

NAME	=	pipex

B_NAME	=	pipex_bonus

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT_A	=	./libft/libft.a

###############################################################################
########### RULES

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C ./libft

bonus:			$(B_NAME)

$(B_NAME):		$(B_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT_A) -o $(B_NAME)

clean:
	make fclean -C ./libft
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus