# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 17:30:11 by fcatala-          #+#    #+#              #
#    Updated: 2023/02/07 15:36:03 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 	= 	libftprintf.a
CC 		= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror -MMD -MP 
LIB		= 	ar rcs
RM 		=  	rm -f


SRCS 	= 	ft_putchar.c ft_printf.c ft_strlen.c ft_strrev.c ft_putstr.c \
			ft_puthexa.c ft_putptr.c ft_putsigbase.c ft_putunsigbase.c

OBJS 	= 	$(SRCS:.c=.o)
DEPS 	= 	$(SRCS:.c=.d)

# Receipts

all:	 	$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $?

clean:
			$(RM) $(OBJS) $(DEPS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

# Other parameters

.PHONY: 	all clean fclean re

-include 	$(DEPS)
