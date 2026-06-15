NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = include
HEADER = $(INC_DIR)/cube.h

SRC_DIR = src

LIBFT_DIR = libft
MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

SRCS = main.c \
	$(SRC_DIR)/utils/free_util.c \
	$(SRC_DIR)/utils/init_parse_struct.c \
	$(SRC_DIR)/utils/init_game.c \
	$(SRC_DIR)/utils/init_all.c \
	$(SRC_DIR)/utils/init_util.c \
	$(SRC_DIR)/utils/set_dir.c \
	$(SRC_DIR)/parsing/parse_colors.c \
	$(SRC_DIR)/parsing/parse_texture.c \
	$(SRC_DIR)/parsing/parse_map.c \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/parsing/utils.c \
	$(SRC_DIR)/check_cub_file/check_cub.c \
	$(SRC_DIR)/check_cub_file/pre_parsing.c \
	$(SRC_DIR)/msg_error/msg_error.c \
	$(SRC_DIR)/render/render.c \
	$(SRC_DIR)/render/raycasting.c \
	$(SRC_DIR)/render/wall.c \
	$(SRC_DIR)/debug/debug.c \
	$(SRC_DIR)/free/free_game.c \
	$(SRC_DIR)/hook/hook_input.c \
	$(SRC_DIR)/hook/rotate.c \
	$(SRC_DIR)/hook/move.c \
	$(SRC_DIR)/parsing/check_map.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MLX_DIR) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) \
		-L$(LIBFT_DIR) -lft \
		-L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz \
		-o $(NAME)

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)

$(OBJS): $(HEADER)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) \
		-c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
