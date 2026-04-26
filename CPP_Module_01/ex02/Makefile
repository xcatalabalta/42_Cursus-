# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 13:13:59 by fcatala-          #+#    #+#              #
#    Updated: 2024/11/23 18:42:06 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	brainref
CC		= 	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		= 	rm -f

# Sources
MAIN	=	main.cpp

# Objects
OBJS	=	$(MAIN:.cpp=.o)

# Targets
all:		$(NAME)
$(NAME):	Makefile  $(MAIN) $(OBJS)
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