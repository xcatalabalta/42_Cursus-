# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 17:11:06 by fcatala-          #+#    #+#              #
#    Updated: 2025/04/13 10:30:40 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General
NAME	=	intern
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror  -std=c++98
RM		= 	rm -f

# Sources and objects
H_DIR		=	incl/
HEAD_FILES	=	Bureaucrat.class.hpp AForm.class.hpp 	\
				PresidentialPardonForm.class.hpp 		\
				ShrubberyCreationForm.class.hpp 		\
				RobotomyRequestForm.class.hpp			\
				Intern.class.hpp 
HEADERS		=	$(addprefix $(H_DIR), $(HEAD_FILES))
MAIN		=	main.cpp
C_DIR		=	class/
CLASS		=	Bureaucrat.class.cpp AForm.class.cpp 	\
				PresidentialPardonForm.class.cpp 		\
				ShrubberyCreationForm.class.cpp			\
				RobotomyRequestForm.class.cpp			\
				Intern.class.cpp 
SRCS		=	$(MAIN) $(addprefix $(C_DIR), $(CLASS))
OBJS		=	$(SRCS:.cpp=.o)

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
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes  ./$(NAME)
			@make fclean

.PHONY: 	all clean fclean re nice run test
