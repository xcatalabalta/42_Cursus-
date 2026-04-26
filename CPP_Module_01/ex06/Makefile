# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 13:13:59 by fcatala-          #+#    #+#              #
#    Updated: 2024/11/25 15:45:08 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	harlFilter
CC		= 	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		= 	rm -f

# Sources
MAIN	=	main.cpp
CLASS	=	Harl.cpp
HEADERS	=	Harl.hpp

# Objects
OBJS	=	$(MAIN:.cpp=.o) $(CLASS:.cpp=.o)

# Targets
all:		$(NAME)
$(NAME):	Makefile $(HEADERS) $(MAIN) $(CLASS) $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

nice:		$(NAME)
			@$(RM) $(OBJS)

.PHONY:		all clean fclean re nice