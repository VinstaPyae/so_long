NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf
SRCS = main.c error.c init.c put_map.c check_map.c check_playable.c
SRC = $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(FTPF) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBFT_DIR)

clean:
	@$(RM) $(OBJ)
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re: fclean all
