# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 12:44:36 by ainatsug          #+#    #+#              #
#    Updated: 2026/04/06 19:46:16 by mitsato          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR   = ./libft
LIBFT		= ${LIBFT_DIR}/libft.a
LIBFT_FLAGS = -L${LIBFT_DIR} -lft

INCLUDE     = -I ./mandatory/includes -I ${LIBFT_DIR}

SRC_DIR		= mandatory/src

OBJ_DIR		= obj

SRC 		= \
			${SRC_DIR}/main.c \
			${SRC_DIR}/init.c

PRINT_DIR	= printer
SRC 		+= \
			${SRC_DIR}/${PRINT_DIR}/print.c

OBJ 		= $(SRC:${SRC_DIR}/%.c=$(OBJ_DIR)/%.o)
MLX_DIR = mlx/
MLX_LIB = mlx/mlx.a
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

.PHONY: all
all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(MLX_DIR): $(MLX_LIB)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(OBJ_DIR)/%.o: mandatory/src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(LIBFT):
	@-$(MAKE) -C $(LIBFT_DIR)

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@-$(MAKE) -C $(MLX_DIR) clean
	@-$(MAKE) -C $(LIBFT_DIR) clean

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@-$(MAKE) -C $(MLX_DIR) fclean
	@-$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: re
re: fclean all
