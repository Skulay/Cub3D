NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INC_DIR = include
SRC_DIR = src

LIBFT_DIR = libft
MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

SRCS = main.c \
	$(SRC_DIR)/free_util.c \
	$(SRC_DIR)/utils/init_parse_struct.c \
	$(SRC_DIR)/utils/init_game.c \
	$(SRC_DIR)/utils/init_all.c \
	$(SRC_DIR)/parsing/parse_colors.c \
	$(SRC_DIR)/parsing/parse_texture.c \
	$(SRC_DIR)/parsing/parse_map.c \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/check_cub_file/check_cub.c \
	$(SRC_DIR)/check_cub_file/pre_parsing.c \
	$(SRC_DIR)/msg_error/msg_error.c \
	$(SRC_DIR)/debug/debug.c \
	$(SRC_DIR)/free/free_game.c \
	$(SRC_DIR)/hook/hook_input.c \
	$(SRC_DIR)/parsing/check_map.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

-include $(DEPS)

all: $(NAME)

$(NAME): $(MLX_DIR) $(OBJS)
	make -C ./$(LIBFT_DIR)
	make -C ./$(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) \
		-L./$(LIBFT_DIR) -lft \
		-L./$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz \
		-o $(NAME)

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I./$(LIBFT_DIR) -I./$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)
	make -C ./$(LIBFT_DIR) clean
	make -C ./$(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C ./$(LIBFT_DIR) fclean
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re