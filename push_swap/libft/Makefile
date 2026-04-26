# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 17:30:11 by fcatala-          #+#    #+#              #
#    Updated: 2023/10/05 08:07:56 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libft.a
CC 		= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror -MMD -MP 
LIB		= 	ar rcs
RM 		=  	rm -f

# Functions of lists NOT included and struct NOT defined
SRCS 	= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strlcat.c\
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_memchr.c\
			ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c\
			ft_putchar.c ft_printf.c ft_strlen.c ft_strrev.c ft_putstr.c \
			ft_puthexa.c ft_putptr.c ft_putsigbase.c ft_putunsigbase.c \
			ft_clean.c get_next_line_bonus.c

OBJS 	= 	$(SRCS:.c=.o)
DEPS 	= 	$(SRCS:.c=.d)

# Receipts

all:	 	$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $?

clean:
			@$(RM) $(OBJS) $(DEPS)

fclean: 	clean
			@$(RM) $(NAME)

re: 		fclean all

# Other parameters

.PHONY: 	all clean fclean re

-include 	$(DEPS)
