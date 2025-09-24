/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:35:17 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/24 11:48:46 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iteration(t_mandelbrot *mandel, t_mlx *mlx)
{
	double	temp;

	mandel->z_real = 0.0;
	mandel->z_imag = 0.0;
	mandel->c_real = (mandel->x - 480.0) / mlx->zoom + mlx->offset_x;
	mandel->c_imag = (mandel->y - 270.0) / mlx->zoom + mlx->offset_y;
	mandel->iter = 0;
	while (mandel->iter < 100 && 
		   (mandel->z_real * mandel->z_real + mandel->z_imag * mandel->z_imag) < 4.0)
	{
		temp = mandel->z_real * mandel->z_real - mandel->z_imag * mandel->z_imag + mandel->c_real;
		mandel->z_imag = 2 * mandel->z_real * mandel->z_imag + mandel->c_imag;
		mandel->z_real = temp;
		mandel->iter++;
	}
	return (mandel->iter);
}

void	draw_mandelbrot(t_mlx *mlx)
{
	t_mandelbrot	mandel;

	mandel.max_iter = 50;
	mandel.y = -1;
	while (++mandel.y < 540)
	{
		mandel.x = -1;
		while (++mandel.x < 960)
		{
			mandelbrot_iteration(&mandel, mlx);
			mandel.color = get_mandel_color(&mandel);
			put_pixel_to_image(mlx, mandel.x, mandel.y, mandel.color);
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}