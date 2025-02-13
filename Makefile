# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 15:31:38 by msmajdor          #+#    #+#              #
#    Updated: 2025/02/03 19:01:13 by mwiacek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC          := cc
CFLAGS      := -g -Wall -Wextra -Werror -Iincludes -Ilibs/libft -Ilibs/minilibx -I.

# Project files
NAME        := cub3d
SRCS        := $(wildcard *.c) $(wildcard draw/*.c)
OBJS        := $(SRCS:.c=.o)

# Clean up
RM          := rm -f

# Libraries
LIB_DIRS = libs/libft libs/minilibx
LIBS = m ft mlx Xext X11
LDFLAGS = $(addprefix -L, $(LIB_DIRS)) $(addprefix -l, $(LIBS))

# Minilibx settings
MLX_DIR 	:= libs/minilibx
MLX_REPO 	:= https://github.com/42Paris/minilibx-linux.git
MLX     	:= $(MLX_DIR)/libmlx.a

# Default target
all: $(MLX) $(LIBS) $(NAME)

# Clone minilibx if the directory doesn't exist, then compile it
$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi

# Compile libft
$(LIBS):
	@$(foreach dir, $(LIB_DIRS), make -C $(dir);)

# Link object files into the final executable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

# Compile each .c file into an object (.o)
%.o: %.c cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@$(foreach dir, $(LIB_DIRS), $(RM) $(dir)/*.o;)
	@$(RM) $(OBJS)

# Clean and remove the final executable
fclean: clean
	@$(foreach dir, $(LIB_DIRS), $(RM) $(dir)/*.a;)
	@$(RM) $(NAME)
	@if [ -d "$(MLX_DIR)" ]; then \
		rm -rf libs/minilibx; \
	fi

# Rebuild everything (fclean + all)
re: fclean all

# Mark these targets as phony to avoid conflicts with files named clean, fclean, etc.
.PHONY: all clean fclean re
