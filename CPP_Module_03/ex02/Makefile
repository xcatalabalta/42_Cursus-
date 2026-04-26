# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 17:11:06 by fcatala-          #+#    #+#              #
#    Updated: 2025/01/18 15:00:29 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General
NAME	=	FragTrap
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -Wshadow -std=c++98
RM		= 	rm -f

# Sources and objects
HEADERS	=	ClapTrap.class.hpp ScavTrap.class.hpp FragTrap.class.hpp
MAIN	=	main.cpp
CLASS	=	ClapTrap.class.cpp ScavTrap.class.cpp FragTrap.class.cpp
SRCS	=	$(MAIN) $(CLASS)
OBJS	=	$(SRCS:.cpp=.o)

# Targets
all:		$(NAME)

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)
	
$(NAME): 	Makefile $(HEADERS) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

nice:		$(NAME) clean

run:		nice
			@echo "\033[32m\nLet's run \033[1;3;32m$(NAME)\033[0;32m program:\033[0m\n"
			@./$(NAME)

.PHONY: 	all clean fclean re nice run