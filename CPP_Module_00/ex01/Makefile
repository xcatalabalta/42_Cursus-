# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 08:06:00 by fcatala-          #+#    #+#              #
#    Updated: 2024/11/14 15:08:37 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	phonebook
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			= 	rm -f

# Sources
MAIN		=	main.cpp
CLASS		=	Contact.class.cpp PhoneBook.class.cpp
HEADERS		=	Contact.class.hpp PhoneBook.class.cpp

# Objects
OBJS		=	$(MAIN:.cpp=.o) $(CLASS:.cpp=.o)

# Others
MESSAGE		=	"\n\e[1;96mClear the screen for a better user experience\e[0m\n"

# Targets
all:			$(NAME)

$(NAME):		Makefile $(HEADERS) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo $(MESSAGE)

%.o:			%.cpp
				$(CC) $(CFLAGS) -c $< -o $@
clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
