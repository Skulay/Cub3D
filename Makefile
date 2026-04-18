NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror # -O3 -flto -ffast-math -march=native -pipe

SRCS = main.c 
OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42paris/minilibx-linux

all: $(NAME)

$(NAME): $(MLX_DIR) $(OBJS)
	make -C ./libft
	make -C ./$(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) \
		-L./libft -lft \
		-L./$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz \
		-o $(NAME)

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I./$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
