NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
INC_DIR = include

SRCS = main.c \
       $(SRC_DIR)/free_util.c \
       $(SRC_DIR)/init_struct.c \
       $(SRC_DIR)/parsing/parse_colors.c \
       $(SRC_DIR)/parsing/parse_texture.c \
       $(SRC_DIR)/parsing/parsing.c \
       $(SRC_DIR)/parsing/verif_map.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)  # Supprimer tous les objets générés dans le répertoire src
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re