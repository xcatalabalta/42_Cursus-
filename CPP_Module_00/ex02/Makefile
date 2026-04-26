# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 16:50:52 by fcatala-          #+#    #+#              #
#    Updated: 2024/10/27 12:17:40 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	margincall
CC 			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

# Sources
MAIN		=	tests.cpp
CLASS		=	Account.cpp
HEADERS		=	Account.hpp

# Objects
OBJS 		=	$(MAIN:.cpp=.o) $(CLASS:.cpp=.o)

# Targets
all:			$(NAME)

$(NAME):		Makefile $(HEADERS) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: 			%.cpp
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			fclean $(NAME)

.PHONY: 		all clean fclean re
# DONE
