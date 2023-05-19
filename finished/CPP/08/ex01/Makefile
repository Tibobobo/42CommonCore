# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 15:58:48 by tgrasset          #+#    #+#              #
#    Updated: 2023/05/08 16:13:21 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########### VARIABLES

SRCS	=	./main.cpp \
			./Span.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

NAME	=	span

CXX		=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

###############################################################################
########### RULES

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re