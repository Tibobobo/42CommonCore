# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 15:58:48 by tgrasset          #+#    #+#              #
#    Updated: 2023/04/07 12:06:37 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########### VARIABLES

SRCS	=	./main.cpp \
			./Zombie.cpp \
			./newZombie.cpp \
			./randomChump.cpp \

OBJS	=	$(SRCS:%.cpp=%.o)

NAME	=	zombie

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