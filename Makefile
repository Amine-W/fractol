# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 11:07:32 by amwahab           #+#    #+#              #
#    Updated: 2025/09/24 12:41:01 by amwahab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra -O2

SRC = fractol.c events.c exit.c julia.c mandelbrot.c fractal.c utils.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(LIBFT) $(PRINTF) mlx $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "libft ok"

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)
	@echo "ft_printf ok"

mlx:
	@$(MAKE) -s -C minilibx-linux
	@echo "mlx ok"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	@echo "fractol ok"

clean:
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@$(MAKE) -s clean -C $(PRINTF_DIR)
	@$(MAKE) -s clean -C minilibx-linux
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx