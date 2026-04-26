# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 13:52:55 by fcatala-          #+#    #+#              #
#    Updated: 2024/11/25 15:42:56 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	replace
CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -std=c++98

# Main program source file and objects
MAIN_SRC			= 	main.cpp
MAND_OBJ			=	$(MAIN_SRC:.cpp=.o)

# Targets
all:					$(NAME)

$(NAME):				Makefile $(MAIN_SRC) $(MAND_OBJ)
						$(CC) $(CFLAGS) -o $(NAME) $(MAND_OBJ)

%.o:					%.cpp
						$(CC) $(CFLAGS) -c $< -o $@

clean:
						@rm -f $(MAND_OBJ)

fclean:					clean
						@rm -f $(NAME)

re:						fclean all

.PHONY: 				all clean fclean re
