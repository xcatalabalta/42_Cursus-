# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 17:11:06 by fcatala-          #+#    #+#              #
#    Updated: 2025/03/06 18:10:22 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General
NAME	=	AMateria
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror  -std=c++98
RM		= 	rm -f

# Sources and objects
HEADERS	=	AMateria.class.hpp Character.class.hpp Cure.class.hpp Ice.class.hpp \
			ICharacter.class.hpp IMateriaSource.class.hpp MateriaSource.class.hpp
MAIN	=	main.cpp
CLASS	=	AMateria.class.cpp Character.class.cpp Cure.class.cpp Ice.class.cpp \
			MateriaSource.class.cpp
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
			valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
			@make fclean

.PHONY: 	all clean fclean re nice run test