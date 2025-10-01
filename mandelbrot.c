/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:35:17 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/25 17:45:09 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iteration(t_mandelbrot *mandel, t_mlx *mlx)
{
	double	temp;

	mandel->z_real = 0.0;
	mandel->z_imag = 0.0;
	mandel->c_real = (mandel->x - 350.0) / mlx->zoom + mlx->offset_x;
	mandel->c_imag = (mandel->y - 350.0) / mlx->zoom + mlx->offset_y;
	mandel->iter = 0;
	while (mandel->iter < mandel->max_iter && (mandel->z_real * mandel->z_real
			+ mandel->z_imag * mandel->z_imag) < 4.0)
	{
		temp = (mandel->z_real * mandel->z_real)
			- mandel->z_imag * mandel->z_imag + mandel->c_real;
		mandel->z_imag = 2 * mandel->z_real * mandel->z_imag + mandel->c_imag;
		mandel->z_real = temp;
		mandel->iter++;
	}
	return (mandel->iter);
}

void	draw_mandelbrot(t_mlx *mlx)
{
	t_mandelbrot	mandel;

	mandel.max_iter = mlx->iter_count;
	mandel.y = -1;
	while (++mandel.y < 700)
	{
		mandel.x = -1;
		while (++mandel.x < 700)
		{
			mandelbrot_iteration(&mandel, mlx);
			mandel.color = get_mandel_color(&mandel);
			put_pixel_to_image(mlx, mandel.x, mandel.y, mandel.color);
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}
