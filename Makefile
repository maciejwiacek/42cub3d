NAME = cub3d

SRC_DIR = src

SRC_FILES = main.c \
			utils/error_funcs.c utils/check_extension.c \
			init/init_game.c \
			map/parse_map.c \

SRC = $(foreach file,$(SRC_FILES),$(SRC_DIR)/$(file))
MLX = minilibx-linux
OBJ = $(SRC:.c=.o)

all: clone $(NAME)

clone:
	if [ ! -d "minilibx-linux" ]; then \
  		git clone https://github.com/42Paris/minilibx-linux.git; \
  	fi

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	make -C my_lib
	make -C $(MLX)
	cc -Wall -Wextra -Werror -L$(MLX) -lmlx_Linux -lX11 -lXext -lm $(OBJ) my_lib/my_lib.a -o $(NAME)

clean:
	make -C my_lib clean
	rm -f $(OBJ)

fclean: clean
	make -C my_lib fclean
	rm -rf $(MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
