# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 09:28:19 by fcatala-          #+#    #+#              #
#    Updated: 2023/10/16 10:16:31 by fcatala-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile identically copied from original library minilibx_opengl.tgz
# Too many scary and unuseful warnings in the original Makefile

NOM		=	libmlx.a
SRC		= 	mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m \
			mlx_xpm.c mlx_int_str_to_wordtab.c
SRC		+= 	mlx_png.c mlx_mouse.m
OBJ1	=	$(SRC:.c=.o)
OBJ		=	$(OBJ1:.m=.o)
CFLAGS	+=	-O2

# add to match string put with X11 in size and position
CFLAGS	+= -DSTRINGPUTX11

# Override of the implicit rule for generating object files in 100% 
# silent mode. Warnings suppresed by > /dev/null 2>&1

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

%.o: %.m
			@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

# Original Makefile continues here
all: 		$(NOM)

$(NOM):		$(OBJ)
			@ar -r $(NOM) $(OBJ) 
			@ranlib $(NOM) > /dev/null 2>&1

clean:
			@rm -f $(NOM) $(OBJ) *~

# Rule fclean added to match our standards
# clean is intentionally not used as precedent 
fclean:
			@rm -f $(NOM) $(OBJ) *~
			@rm -f mlx_app

re: 		fclean all

.PHONY:		all clean fclean re
