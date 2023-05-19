# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 15:58:48 by tgrasset          #+#    #+#              #
#    Updated: 2023/04/11 16:23:33 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########### VARIABLES

SRCS	=	./main.cpp \
			./Fixed.cpp \

OBJS	=	$(SRCS:%.cpp=%.o)

NAME	=	fixed3

CPP		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

###############################################################################
########### RULES

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re