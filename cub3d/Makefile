# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 18:28:01 by mvisca-g          #+#    #+#              #
#    Updated: 2025/02/27 16:36:00 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------- FORMAT ----------------------#

RED			:=	\033[0;31m
GREEN		:=	\033[0;32m
YELLOW		:=	\033[0;33m
BLUE		:=	\033[0;34m
NC			:=	\033[0m

#---------- TARGET ----------------------#

NAME		:=	cub3d

#test
#---------- FILES & DIRS ----------------#

#excluded srcs/c3d_player.c srcs/c3d_run.c

SRC			:=	srcs/c3d.c						\
				srcs/c3d_errors.c				\
				srcs/c3d_free1.c				\
				srcs/c3d_free2.c				\
				srcs/c3d_init.c					\
				srcs/c3d_logic_utils.c			\
				srcs/c3d_parse_process.c		\
				srcs/c3d_parse.c				\
				srcs/c3d_render.c				\
				srcs/c3d_render_2d_1.c			\
				srcs/c3d_render_2d_2.c			\
				srcs/c3d_render_3d_1.c			\
				srcs/c3d_render_3d_2.c			\
				srcs/c3d_render_init.c			\
				srcs/c3d_render_move.c			\
				srcs/c3d_render_hooks.c			\
				srcs/c3d_render_get.c			\
				srcs/c3d_render_utils.c			\
				srcs/c3d_utils.c				\
				srcs/c3d_validate_arg.c			\
				srcs/c3d_validate_map.c			\
				srcs/c3d_validate_map_closed.c	\
				srcs/c3d_validate_rgb.c			\
				srcs/c3d_validate_texture.c		\
				srcs/c3d_validate.c				
				

OBJ			:=	$(addprefix .build/, $(notdir $(SRC:.c=.o)))

DEP			:=	$(OBJ:.o=.d)

HEADERS		:=	includes/structs.h	\
			   	includes/cub3d.h

LFTDIR		:=	libs/libft/
GNLDIR		:=	libs/gnl/
MLXDIR		:=	libs/minilibx-linux/

#---------- LIBS ------------------------#

LIBFT		:=	$(LFTDIR)libft.a
LIGNL		:=	$(GNLDIR)libgnl.a
MLX			:=	$(MLXDIR)libmlx.a

#---------- INGREDIENTS ---------------------#

CC			:=	cc
FLAGS		:=	-Wall -Wextra -Werror -MMD

LFTFLAGS	:=	-L$(LFTDIR) -lft -I$(LFTDIR)include
GNLFLAGS	:=	-L$(GNLDIR) -lgnl -I$(GNLDIR)include
MLXFLAGS 	:=	-L$(MLXDIR) -lmlx_Linux -L/usr/lib -lX11 -lXext -lm -lz -I$(MLXDIR)


#---------- RECIPES ---------------------#

all: mlx libft libgnl $(NAME) | callforlib

bonus: all

$(NAME): $(OBJ) $(HEADERS) Makefile
	@$(CC) $(FLAGS) $(SRC) $(MLXFLAGS) $(LFTFLAGS) $(GNLFLAGS) -o $(NAME)
	@echo "$(YELLOW)Packing $(RED)$(NAME) $(YELLOW)ready!$(NC)"

mlx:
	@$(MAKE) -C $(MLXDIR) --silent
	
libft:
	@$(MAKE) -C $(LFTDIR) --silent

libgnl:
	@$(MAKE) -C $(GNLDIR) --silent
-include $(DEP)

.build/%.o: srcs/%.c $(HEADERS) $(MLX) $(LIBFT) Makefile
	@mkdir -p .build
	@$(CC) $(FLAGS) $< -c -o $@
	@echo "$(GREEN)Creating... $(NC)$(notdir $<) $(RED)-> $(NC)$(notdir $@)"



#---------- OTHERS -----------------------#

callforlib: mlx libft libgnl

clean:
	@$(MAKE) -C $(MLXDIR) clean --silent
	@$(MAKE) -C $(LFTDIR) clean --silent
	@$(MAKE) -C $(GNLDIR) clean --silent
	@rm -rf cub3d.d
	@rm -rf .build

fclean: clean
	@rm -rf cub3d cub3d.d
	@$(MAKE) -C $(LFTDIR) fclean --silent
	@$(MAKE) -C $(GNLDIR) fclean --silent

re: fclean all

run: 	all
		./$(NAME) assets/maps/ok5.cub

test:	all
		valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME) assets/maps/ok3.cub

.PHONY: all bonus mlx libft libgnl callforlib clean fclean re run test
