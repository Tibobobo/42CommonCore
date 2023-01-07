# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:51:27 by tgrasset          #+#    #+#              #
#    Updated: 2022/11/24 10:41:28 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./ft_printf.c \
			./conv_functions/print_char.c \
			./conv_functions/print_dec.c \
			./conv_functions/print_int.c \
			./conv_functions/print_low_hex.c \
			./conv_functions/print_percent.c \
			./conv_functions/print_ptr.c \
			./conv_functions/print_str.c \
			./conv_functions/print_unsigned_dec.c \
			./conv_functions/print_up_hex.c \
			
		
OBJS	=	$(SRCS:%.c=%.o)

NAME	=	libftprintf.a

INCL	=	./includes

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re
