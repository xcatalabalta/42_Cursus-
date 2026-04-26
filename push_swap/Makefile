# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:17:47 by fcatala-          #+#    #+#              #
#    Updated: 2023/10/05 08:29:32 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -MMD -MP 

# Main program source file (no bonus this time)
MAIN_SRC			=	$(NAME)_main.c

# Utils: Large functions: ft_*.c Short functions: contained in utils_*.c
UTILS_DIR			=	./srcs/
UTILS_PROG			=	utils_1.c ft_chck.c utils_list.c \
						utils_mov_swap.c utils_mov_push.c utils_mov_rot.c \
						utils_mov_revrot.c utils_sort_simple.c \
						utils_paramet.c
UTILS_SRC			=	$(addprefix $(UTILS_DIR), $(UTILS_PROG))

# Objects and Deps
MAND_OBJ			=	$(MAIN_SRC:.c=.o) $(UTILS_SRC:.c=.o)
MAND_DEPS			=	$(MAIN_SRC:.c=.d) $(UTILS_SRC:.c=.d)

# Libft: Makefile included at ./libft
LIBFT_DIR			=	./libft
LIBFT				=	$(LIBFT_DIR)/libft.a

# Targets
all: 					$(NAME)

$(NAME):				$(MAND_OBJ) $(LIBFT) 
						$(CC) $(FLAGS) $(MAND_OBJ) $(LIBFT) -o $(NAME)
						@make check_dirs

$(MAND_OBJ):			| lft_update

$(LIBFT):
						@make -C $(LIBFT_DIR)

lft_update:
						@make -C $(LIBFT_DIR)

clean:
						@rm -f *.o *.d
						@rm -f $(UTILS_DIR)/*.o $(UTILS_DIR)/*.d
						@make clean -C $(LIBFT_DIR)
						@make check_dirs

fclean:
						@rm -f *.o *.d $(NAME)
						@rm -f $(UTILS_DIR)/*.o $(UTILS_DIR)/*.d
						@make fclean -C $(LIBFT_DIR)
						@make check_dirs

re:						fclean all

check_dirs:
						@echo "\033[32m\nContent of $(LIBFT_DIR):\n\033[0m"
						@ls $(LIBFT_DIR)
						@echo "\033[32m\nContent of $(NAME) directory:\n\033[0m"
						@ls -lF | awk 'NR>1{print $$1 "\t"$$2 "\t"$$6 "-"$$7 "\t"$$8 "\t"$$9}'
						@echo "\033[32m\nContent of $(UTILS_DIR) directory:\n\033[0m"
						@ls -lF $(UTILS_DIR) | awk 'NR>1{print $$1 "\t"$$2 "\t"$$6 "-"$$7 "\t"$$8 "\t"$$9}'
						@echo "\n"

.PHONY: 				all clean fclean re check_dirs lft_update

-include				$(MAND_DEPS)
