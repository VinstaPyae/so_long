# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klinn <klinn@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 18:35:44 by klinn             #+#    #+#              #
#    Updated: 2024/02/17 11:14:26 by klinn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

INC	=	so_long.h	\
		messages.h	\
		values.h

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDES	=	-I./includes
RM	=	rm -f

all:	$(NAME)

LIBFT_42_PATH	=	libraries/42_library
LIBFT_42	=	$(LIBFT_42_PATH)/libft_42

$(LIBFT_42):
	@make -s -C $(LIBFT_42_PATH)

MLX_FLAGS	=	-L $(MLX_PATH)/ -lmlx -Ilmlx -lXext -lX11
MLX_PATH	=	libraries/minilibx/minilibx-linux
MLX	=	$(MLX_PATH)/libmlx_Linux.a

$(MLX):
	@make -s -C $(MLX_PATH)
	
%.o:	%.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

SRC_DIR	=	source/
SRC_FILES	=	check_map.c	\
				error.c	\
				get_map.c	\
				initialize.c	\
				key_hook.c	\
				main.c	\
				render_map.c	\
				solve_map.c	\
				update_map.c

SRC	+=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ	+=	$(SRC:.c=.o)

$(NAME):	$(OBJ) $(MLX) $(LIBFT_42)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_42) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "## SO_LONG IS READY !! ##"
	
clean:
	@$(RM) $(OBJ)
	@make -s -C $(LIBFT_42_PATH) clean
	@echo ">> cleaned so_long's object files... "

fclean:	clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_42_PATH)
	@echo "## REMOVED ALL SO_LONG'S FILES !! ##"

re:	fclean all

.PHONY: all clean fclean all
