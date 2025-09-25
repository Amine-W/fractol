/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:49:11 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/25 12:55:44 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw_fractal(t_mlx *mlx)
{
	if (mlx->fractal_type == MANDELBROT)
		draw_mandelbrot(mlx);
	else if (mlx->fractal_type == BURNINGSHIP)
		draw_burningship(mlx);
	else if (mlx->fractal_type == JULIA)
		draw_julia(mlx, mlx->julia_c_real, mlx->julia_c_imag);
}

int	handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	double	mouse_real;
	double	mouse_imag;

	mouse_real = (x - 350.0) / mlx->zoom + mlx->offset_x;
	mouse_imag = (y - 350.0) / mlx->zoom + mlx->offset_y;
	if (button == 4)
		mlx->zoom *= 1.5;
	else if (button == 5)
		mlx->zoom *= 0.7;
	else
		return (0);
	mlx->offset_x = mouse_real - (x - 350.0) / mlx->zoom;
	mlx->offset_y = mouse_imag - (y - 350.0) / mlx->zoom;
	redraw_fractal(mlx);
	return (0);
}
