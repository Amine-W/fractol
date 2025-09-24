/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:36:52 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/24 13:07:23 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iteration(t_julia *julia, t_mlx *mlx)
{
	double	zx;
	double	zy;
	double	temp;

	zx = (julia->x - 350) / mlx->zoom + mlx->offset_x;
	zy = (julia->y - 350) / mlx->zoom + mlx->offset_y;
	julia->iter = 0;
	while (julia->iter < julia->max_iter && (zx * zx + zy * zy) < 4.0)
	{
		temp = zx * zx - zy * zy + julia->c_real;
		zy = 2 * zx * zy + julia->c_imag;
		zx = temp;
		julia->iter++;
	}
	return (julia->iter);
}

void	draw_julia(t_mlx *mlx, double c_r, double c_i)
{
	t_julia	julia;

	julia.c_real = c_r;
	julia.c_imag = c_i;
	julia.max_iter = 80;
	julia.y = -1;
	while (++julia.y < 700)
	{
		julia.x = -1;
		while (++julia.x < 700)
		{
			julia_iteration(&julia, mlx);
			julia.color = get_julia_color(&julia);
			put_pixel_to_image(mlx, julia.x, julia.y, julia.color);
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}
