# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 17:11:06 by fcatala-          #+#    #+#              #
#    Updated: 2025/06/21 11:10:56 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General
NAME	=	easyfind
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
DFLAGS =	-MMD -MP
RM		= 	rm -f

# Headers and templates commented, but kept for the sake of control
# H_DIR	=	incl/
# HEADERS	=	$(addprefix $(H_DIR), easyfind.class.hpp)
# T_DIR	=	templ/
# TEMPL 	= 	$(addprefix $(T_DIR), easyfind.class.tpp)
# Sources and objects
MAIN	=	main.cpp
SRCS	=	$(MAIN)
OBJS	=	$(SRCS:.cpp=.o)
DEPS	=	$(OBJS:.o=.d)

# Targets
all:		$(NAME)

%.o: 		%.cpp
			$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@
	
$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS) $(DEPS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

nice:		$(NAME) clean

run:		nice
			@echo "\033[32m\nLet's run \033[1;3;32m$(NAME)\033[0;32m program:\033[0m\n"
			@./$(NAME)
			@make fclean

test:		$(NAME)
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)
			@make fclean

# Include dependency files if they exist
-include $(DEPS)

.PHONY: 	all clean fclean re nice run test
