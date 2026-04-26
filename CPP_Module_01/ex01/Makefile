# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 13:13:59 by fcatala-          #+#    #+#              #
#    Updated: 2024/11/25 15:40:54 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	zombie
CC		= 	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		= 	rm -f

# Sources
MAIN	=	main.cpp
CLASS	=	Zombie.class.cpp
HEADERS	=	Zombie.class.hpp
SRCS	=	zombieHorde.cpp

# Objects
OBJS	=	$(MAIN:.cpp=.o) $(CLASS:.cpp=.o) $(SRCS:.cpp=.o)

# Targets
all:		$(NAME)
$(NAME):	Makefile $(HEADERS) $(CLASS) $(SRCS) $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			
re:			fclean $(NAME)

nice:		$(NAME) clean

.PHONY:		all clean fclean re nice