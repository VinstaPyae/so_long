# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klinn <klinn@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 16:10:40 by klinn             #+#    #+#              #
#    Updated: 2024/04/09 22:55:05 by klinn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft_42

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR	=	ar -rcs
RM	=	rm -f

BUILD_DIR	=	./build
FT_PRINTF_DIR	=	./ft_printf/
GNL_DIR	=	./get_next_line/
LIBFT_DIR	=	./libft/

FT_PRINTF	=	ft_printf_utils.c	\
				ft_utils_spt.c	\
				ft_printf.c	\
				ft_subft.c	\
				ft_sec_subft.c

FT_PRINTF_SRC	=	$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF))

GNL	=	get_next_line.c	\
		get_next_line_utils.c

GNL_SRC	=	$(addprefix $(GNL_DIR), $(GNL))

LIBFT	=	ft_atoi.c \
			ft_bzero.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_strlcpy.c \
			ft_substr.c \
			ft_split.c \
			ft_strncmp.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_calloc.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
	    	ft_lstlast.c \
	    	ft_lstadd_back.c \
	    	ft_lstdelone.c \
	    	ft_lstclear.c \
			ft_lstdisplay.c \
			ft_free_matrix.c

LIBFT_SRC	=	$(addprefix $(LIBFT_DIR), $(LIBFT))

SRC	=	$(FT_PRINTF_SRC) $(GNL_SRC) $(LIBFT_SRC)

FT_PRINTF_OBJ	=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(FT_PRINTF_SRC))
GNL_OBJ	=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(GNL_SRC))
LIBFT_OBJ	=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(LIBFT_SRC))

OBJ	=	$(FT_PRINTF_OBJ) $(GNL_OBJ) $(LIBFT_OBJ)

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(AR) $@ $(OBJ)
		@echo "## COMPILED << libft_42 >> SUCCESSFULLY !! ##"

$(BUILD_DIR)/%.o:	%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:	
	@$(RM) $(OBJ)
	@if [ -d $(BUILD_DIR) ]; then \
		rm -rf $(BUILD_DIR);	\
	fi
	@echo ">> cleaned libft_42's object files... "

fclean:	clean
	@$(RM) $(NAME)
	@echo "## REMOVED ALL LIBFT_42'S FILES !! ##"

re:	fclean all

.PHONY: all clean fclean all
