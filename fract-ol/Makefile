# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 07:57:30 by fcatala-          #+#    #+#              #
#    Updated: 2023/10/23 16:40:40 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General definition
NAME				=	fractol
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -MMD -MP

# Special flags to run the program in Mac
C_MAC				=	-framework OpenGL -framework AppKit

# Main program source file 
MAIN_SRC			=	$(NAME)_main.c

# Utils 
UTILS_DIR			=	./srcs/
UTILS_PROG			=	controls.c fractal.c utils_fr.c
UTILS_SRC			=	$(addprefix $(UTILS_DIR), $(UTILS_PROG))

# Objects and Deps
MAND_OBJ			=	$(MAIN_SRC:.c=.o) $(UTILS_SRC:.c=.o)
MAND_DEPS			=	$(MAIN_SRC:.c=.d) $(UTILS_SRC:.c=.d)

# Libraries
# Libft: Makefile included at ./libft
# mlx: Makefile included at ./mlx
LIBFT_DIR			=	./libft
LIBFT				=	$(LIBFT_DIR)/libft.a
MLX_DIR				=	./mlx
MLX					=	$(MLX_DIR)/libmlx.a

# Targets
all: 					$(NAME)

$(NAME):				$(MAND_OBJ) $(LIBFT) 
						@make -C $(MLX_DIR)
						$(CC) $(FLAGS) $(MAND_OBJ) $(LIBFT) $(MLX) $(C_MAC) -o $(NAME)
						@make chck_dirs
						@make menuf

$(MAND_OBJ):			| lft_update

$(LIBFT):
						@make -C $(LIBFT_DIR)

lft_update:
						@make -C $(LIBFT_DIR)

clean:
						@rm -f *.o *.d
						@rm -f $(UTILS_DIR)/*.o $(UTILS_DIR)/*.d
						@make clean -C $(LIBFT_DIR)
						@make clean -C $(MLX_DIR)
						@make chck_dirs

fclean:
						@rm -f *.o *.d $(NAME)
						@rm -f $(UTILS_DIR)/*.o $(UTILS_DIR)/*.d
						@make fclean -C $(LIBFT_DIR)
						@make clean -C $(MLX_DIR)
						@make chck_dirs

re:						fclean all

chck_dirs:
						@echo "\033[32m\nContent of $(LIBFT_DIR):\n\033[0m"
						@ls $(LIBFT_DIR)
						@echo "\033[32m\nContent of $(NAME) directory:\n\033[0m"
						@ls -lF | awk 'NR>1{print $$1 "\t"$$2 "\t"$$6 "-"$$7 "\t"$$8 "\t"$$9}'
						@echo "\033[32m\nContent of $(UTILS_DIR) directory:\n\033[0m"
						@ls -lF $(UTILS_DIR) | awk 'NR>1{print $$1 "\t"$$2 "\t"$$6 "-"$$7 "\t"$$8 "\t"$$9}'
						@echo "\n"

menuf:					
						@echo "\033[32mValid set of options:\n"
						@echo "1.- Fractal types:\n\tMandelbrot\n\tJulia\n"
						@echo "2.- Iterations from 5 to 100\n"
						@echo "3.- Initial parameters (for Julia only)\n"
						@echo "\tReal component [-3;3]\n"
						@echo "\tImaginary component [-1;1]\n"
						@echo "Example: Julia 50 -0.8 0.156"
						@echo "\nControl options:\n"
						@echo "\tMove image with arrow keys\n"
						@echo "\tZoom in/out with mouse wheel or +/- keys\n"
						@echo "\tMove point to center with mouse clic\n\033[0m"


.PHONY: 				all clean fclean re chck_dirs lft_update menuf

-include				$(MAND_DEPS)
