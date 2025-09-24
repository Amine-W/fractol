/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:01:32 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/24 13:04:55 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	if (keycode == 65307)
		exit_fractol(mlx, "Escape pressed");
	return (0);
}

int	handle_close(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->init, mlx->win);
	mlx_destroy_display(mlx->init);
	free(mlx->init);
	exit(0);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	double	mouse_real;
	double	mouse_imag;

	mouse_real = (x - 350.0) / mlx->zoom + mlx->offset_x;
	mouse_imag = (y - 350.0) / mlx->zoom + mlx->offset_y;
	if (button == 4)
	{
		mlx->zoom *= 1.5;
		mlx->offset_x = mouse_real - (x - 350.0) / mlx->zoom;
		mlx->offset_y = mouse_imag - (y - 350.0) / mlx->zoom;
	}
	else if (button == 5)
	{
		mlx->zoom *= 0.7;
		mlx->offset_x = mouse_real - (x - 350.0) / mlx->zoom;
		mlx->offset_y = mouse_imag - (y - 350.0) / mlx->zoom;
	}
	if (mlx->fractal_type == MANDELBROT)
		draw_mandelbrot(mlx);
	else if (mlx->fractal_type == JULIA)
		draw_julia(mlx, mlx->julia_c_real, mlx->julia_c_imag);
	return (0);
}
