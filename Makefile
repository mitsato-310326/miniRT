# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 12:44:36 by ainatsug          #+#    #+#              #
#    Updated: 2026/03/05 20:48:15 by mitsato          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread

INCLUDE     = -I ./mandatory/includes

OBJ_DIR		= obj

SRC 		= \
			mandatory/src/main.c

OBJ 		= $(SRC:mandatory/src/%.c=$(OBJ_DIR)/%.o)
MLX_LIB = mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) ${INCLUDE} $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: mandatory/src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@-$(MAKE) -C $(MLX_LIB) clean

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re: fclean all
