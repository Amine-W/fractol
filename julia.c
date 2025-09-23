/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juila.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:36:52 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/23 16:03:24 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx->img_data + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(int *)pixel = color;
}

int	get_color(t_julia *julia)
{
	int	r;
	int	g;
	int	b;

	if (julia->iter == julia->max_iter)
		return (0x000000);
	r = (julia->iter * 9) % 255;
	g = (julia->iter * 15) % 255;
	b = (julia->iter * 25) % 255;
	return ((r << 16) | (g << 8) | b);
}

int	julia_iteration(t_julia *julia)
{
	double	zx;
	double	zy;
	double	temp;

	zx = (julia->x - 960.0) * 4.0 / 1920.0;
	zy = (julia->y - 540.0) * 4.0 / 1080.0;
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
	julia.max_iter = 100;
	julia.y = -1;
	while (++julia.y < 1080)
	{
		julia.x = -1;
		while (++julia.x < 1920)
		{
			julia_iteration(&julia);
			julia.color = get_color(&julia);
			put_pixel(mlx, julia.x, julia.y, julia.color);
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}