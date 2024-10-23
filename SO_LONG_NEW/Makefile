NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
FTPF_DIR = ./libs/ft_printf
FTPF = $(FTPF_DIR)/libftprintf.a
MLX_PATH = ./libs/minilibx/minilibx-linux
MLX = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS = -L $(MLX_PATH)/ -lmlx -Ilmlx -lXext -lX11
RM = rm -rf
SRCS = main.c error.c init.c put_map.c check_map.c check_playable.c render_map.c update_game.c key_hook.c
SRC = $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(FTPF) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	
$(FTPF):
	@make -s -C $(FTPF_DIR)

$(MLX):
	@make -s -C $(MLX_PATH)

$(NAME): $(LIBFT) $(FTPF) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(FTPF_DIR) -lftprintf $(MLX) $(MLX_FLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBFT_DIR) -I$(FTPF_DIR) -I$(MLX_PATH)

clean:
	@$(RM) $(OBJ)
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(FTPF_DIR) clean
	@make -s -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(FTPF_DIR) fclean
	@$(RM) $(MLX_PATH)/libmlx_Linux.a

re: fclean all

.PHONY: all clean fclean re
