# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:58:06 by tgrasset          #+#    #+#              #
#    Updated: 2023/02/13 16:09:18 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########### VARIABLES

SRCS	=	./main.c \
			./lexer.c \
			./lexer_token_count.c \
			./lexer_token_extract.c \
			./parser.c \
			./parser_2.c \
			./var_expand.c \
			./parser_utils.c \
			./parser_syntax_check.c \
			
OBJS	=	$(SRCS:%.c=%.o)

NAME	=	minishell

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

###############################################################################
########### RULES

all:		$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -lreadline $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	make fclean -C ./libft
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re