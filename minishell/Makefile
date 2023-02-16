# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:58:06 by tgrasset          #+#    #+#              #
#    Updated: 2023/02/16 14:27:44 by tgrasset         ###   ########.fr        #
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
			./var_expand_utils.c \
			./parser_utils.c \
			./parser_syntax_check.c \
			./free.c \
			./execution.c \
			./execution_utils.c \
			./redirection.c \
			./redirection_utils.c \
			
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
