/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:35:25 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/24 13:06:24 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		return (1);
	mlx.init = mlx_init();
	mlx.zoom = 100.0;
	mlx.offset_x = -0.5;
	mlx.offset_y = 0.0;
	mlx.win = mlx_new_window(mlx.init, 700, 700, "Fractol");
	mlx.img = mlx_new_image(mlx.init, 700, 700);
	mlx.img_data = mlx_get_data_addr(mlx.img,
			&mlx.bpp, &mlx.line_len, &mlx.endian);
	fractal(argc, argv, &mlx);
	mlx_key_hook(mlx.win, handle_keypress, &mlx);
	mlx_hook(mlx.win, 17, 0, handle_close, &mlx);
	mlx_hook(mlx.win, 4, 1L << 2, handle_mouse, &mlx);
	mlx_loop(mlx.init);
	mlx_destroy_window(mlx.init, mlx.win);
	mlx_destroy_display(mlx.init);
	return (0);
}
