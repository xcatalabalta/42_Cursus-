# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 17:11:06 by fcatala-          #+#    #+#              #
#    Updated: 2025/06/26 18:37:10 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General
NAME	=	btc
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror  -std=c++98
DFLAGS =	-MMD -MP
RM		= 	rm -f

# Headers and templates commented, but kept for the sake of control
# H_DIR	=	incl/
# HEADERS	=	$(addprefix $(H_DIR), BitcoinExchange.class.hpp)
# T_DIR 	= templ/
# TEMPLATE 	= LACLASS.class.tpp
# Sources and objects
C_DIR	=	class/
CLASS 	=	$(addprefix $(C_DIR), BitcoinExchange.class.cpp)
MAIN	=	main.cpp
SRCS	=	$(MAIN) $(CLASS)
OBJS	=	$(SRCS:.cpp=.o)
DEPS	=	$(OBJS:.o=.d)

# Targets
all:		$(NAME)

%.o: 		%.cpp
			$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@
	
$(NAME): 	Makefile $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS) $(DEPS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

nice:		$(NAME) clean

run:		nice
			@echo "\033[32m\nLet's run \033[1;3;32m$(NAME)\033[0;32m program:\033[0m\n"
			@./$(NAME) "assets/subject_bdata.txt"
			@make fclean

test:		$(NAME)
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) "assets/subject_bdata.txt"
			@make fclean

# Include dependency files if they exist
-include $(DEPS)

.PHONY: 	all clean fclean re nice run test
