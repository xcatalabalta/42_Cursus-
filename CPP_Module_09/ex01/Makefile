# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 17:11:06 by fcatala-          #+#    #+#              #
#    Updated: 2025/06/01 12:22:48 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General
NAME		=	RPN
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			= 	rm -f

# Sources and objects
HEADERS		=	incl/RPN.class.hpp
MAIN		=	main.cpp
CLASS		=	class/RPN.class.cpp
SRCS		=	$(MAIN) $(CLASS)
OBJS		=	$(SRCS:.cpp=.o)

# Flag files to track build state
VERBO_FLAG 	= .verbose_build
NORMAL_FLAG = .normal_build

# Targets
all:		$(NORMAL_FLAG) $(NAME)

verbo:		$(VERBO_FLAG) $(NAME)

# Main executable target
$(NAME): 	$(HEADERS) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Flag file management - these control when to rebuild
$(VERBO_FLAG):
			@$(RM) $(NORMAL_FLAG) $(OBJS)
			@touch $(VERBO_FLAG)

$(NORMAL_FLAG):
			@$(RM) $(VERBO_FLAG) $(OBJS)
			@touch $(NORMAL_FLAG)

# Object file compilation rules
%.o: %.cpp
			@if [ -f $(VERBO_FLAG) ]; then \
				$(CC) $(CFLAGS) -DVERBOSE=1 -c $< -o $@; \
			else \
				$(CC) $(CFLAGS) -c $< -o $@; \
			fi

clean:
			@$(RM) $(OBJS) $(VERBO_FLAG) $(NORMAL_FLAG)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
 		
run:		$(NAME)
			./$(NAME) "5 4 2 3 + * -"
			@make fclean

test:		
			@./tester.sh
			@make -s fclean

.PHONY: 	all clean fclean re run test verbo