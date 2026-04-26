# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 21:55:28 by mvisca            #+#    #+#              #
#    Updated: 2025/01/23 11:31:43 by mvisca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------------#
#	FORMAT								#
#---------------------------------------#

RED 		:= \033[0;31m
GREEN 		:= \033[0;32m
YELLOW 		:= \033[0;33m
BLUE 		:= \033[0;34m
NC 			:= \033[0m

#---------------------------------------#
#	TARGET								#
#---------------------------------------#

NAME 		:= libgnl.a

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

# Dirs
BUILD_DIR	:= .build/
SRCS_DIR	:= src/
INCS		:= include/

# Sources
SRCS		:=				\
	get_next_line.c			\
	get_next_line_utils.c

SRCS		:= $(SRCS:%=$(SRCS_DIR)%)

# Objects
OBJS		:= $(SRCS:$(SRCS_DIR)%.c=$(BUILD_DIR)%.o)

# Dependencies
DEPS		:= $(OBJS:.o=.d)

#---------------------------------------#
#	UTENSILS							#
#---------------------------------------#

# Compiler
CC 			:= cc

# Compilation flags
CFLAGS 		:= -Wall -Wextra -Werror

# PreProcessor flags
CPPFLAGS	:= $(addprefix -I, $(INCS)) -MMD

# Archiver 
AR			:= ar -r -c -s

# Remover
RM			:= rm -f -r

# Make dir
DIR_DUP		= mkdir -p $(@D)

# Default behaviours update
MAKEFLAGS	+= --no-print-directory


#---------------------------------------#
#	RECIPES								#
#---------------------------------------#

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	@$(AR) $@ $(OBJS)
	@echo "$(YELLOW)Packing $(RED)$(NAME) $(YELLOW)ready!$(NC)"

$(BUILD_DIR)%.o: $(SRCS_DIR)%.c Makefile include/get_next_line.h
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo "$(GREEN)Creating... $(NC)$(notdir $<) $(RED)-> $(NC)$(notdir $@)"

clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		echo "$(RED)Deleting objects for... $(NC)libgnl *.o *.d $(RED)>> 🗑️$(NC)"; \
		$(RM) -r $(BUILD_DIR); \
	fi

fclean: clean
	@echo "$(RED)Deleting... $(NC)$(NAME) $(RED)>> 🗑️$(NC)"
	@$(RM) $(NAME)

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

#---------------------------------------#
#	SPEC								#
#---------------------------------------#

.PHONY: clean fclean re all
