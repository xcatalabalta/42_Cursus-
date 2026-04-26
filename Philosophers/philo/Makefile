# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 16:23:34 by fcatala-          #+#    #+#              #
#    Updated: 2024/01/16 17:04:25 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	philo
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -MMD -MP 

# Sanitizer flags
SFLAGS				=	-fsanitize=thread -g -O1

# Main program source file
MAIN_SRC			= 	main.c 

# Functions and auxiliar programs
UTILS_SRC			= 	launcher.c time_mgr.c utils.c

# Objects and Deps
MAND_OBJ			=	$(MAIN_SRC:.c=.o) $(UTILS_SRC:.c=.o)
MAND_DEPS			=	$(MAIN_SRC:.c=.d) $(UTILS_SRC:.c=.d)

# Targets
all: 					$(NAME)

$(NAME):				$(MAND_OBJ)
						@clear
						$(CC) $(CFLAGS) $(MAND_OBJ) -o $(NAME)

sanit:					$(MAND_OBJ)
						@clear
						$(CC) $(SFLAGS) $(CFLAGS) $(MAND_OBJ) -o $(NAME)

clean:
						@rm -f $(MAND_OBJ) $(MAND_DEPS)

fclean:
						@rm -f $(MAND_OBJ) $(MAND_DEPS) $(NAME)

re:						fclean all

.PHONY: 				all clean fclean re sanit

-include				$(MAND_DEPS)
