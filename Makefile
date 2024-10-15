# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 21:16:43 by pzaw              #+#    #+#              #
#    Updated: 2024/10/15 21:16:43 by pzaw             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf
SRCS = main.c
SRC = $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

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
