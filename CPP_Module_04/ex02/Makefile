# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 17:11:06 by fcatala-          #+#    #+#              #
#    Updated: 2025/03/03 16:31:39 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General
NAME	=	Abstraction
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror  -std=c++98
RM		= 	rm -f

# Sources and objects
HEADERS	=	Brain.class.hpp AAnimal.class.hpp Cat.class.hpp Dog.class.hpp WrongAnimal.class.hpp WrongCat.class.hpp
MAIN	=	main.cpp
CLASS	=	Brain.class.cpp AAnimal.class.cpp Cat.class.cpp Dog.class.cpp WrongAnimal.class.cpp WrongCat.class.cpp
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
			@make fclean

test:		$(NAME)
			valgrind --leak-check=full ./$(NAME)

.PHONY: 	all clean fclean re nice run