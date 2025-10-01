# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+: :+:    :+:        #
#                                                     +:+ +:+         +:+      #
#    By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 11:07:32 by amwahab           #+#    #+#              #
#    Updated: 2025/10/01 12:49:34 by amwahab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra -O2

SRC = fractol.c events.c exit.c julia.c mandelbrot.c fractal.c utils.c burningship.c mouse.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(LIBFT) $(PRINTF) $(MLX_DIR) mlx $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "libft ok"

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)
	@echo "ft_printf ok"

$(MLX_DIR):
	@echo "Cloning MiniLibX..."
	@git clone $(MLX_REPO) $(MLX_DIR)
	@echo "MiniLibX cloned successfully"

mlx: $(MLX_DIR)
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "mlx ok"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	@echo "fractol ok"

clean:
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@$(MAKE) -s clean -C $(PRINTF_DIR)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -s clean -C $(MLX_DIR); fi
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx