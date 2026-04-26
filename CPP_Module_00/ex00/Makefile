# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 13:52:55 by fcatala-          #+#    #+#              #
#    Updated: 2024/10/17 17:53:42 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	megaphone
CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -std=c++98

# Main program source file and objects
MAIN_SRC			= 	megaphone.cpp
MAND_OBJ			=	$(MAIN_SRC:.cpp=.o)

# Targets
all:					$(NAME)

$(NAME):				Makefile $(MAND_OBJ)
						$(CC) $(CFLAGS) -o $(NAME) $(MAND_OBJ)

%.o:					%.cpp
						$(CC) $(CFLAGS) -c $< -o $@

clean:
						rm -f $(MAND_OBJ)

fclean:					clean
						rm -f $(NAME)

re:						fclean all

.PHONY: 				all clean fclean re
