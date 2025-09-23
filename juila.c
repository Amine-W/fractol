/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juila.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:36:52 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/23 13:35:13 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_mlx *mlx, double c_r, double c_i, t_fractal *f)
{
	
}

int julia_iteration(t_fractal *f)
{
	int iter;
	double temp;
	int max_iter;

	iter = 0;
	max_iter = 100;
	while (iter < max_iter && (f->zx * f->zx + f->zy * f->zy) < 4.0)
	{
		temp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2 * f->zx * f->zy + f->cy;
		f->zx = temp;
		iter++;
	}
	return (iter);
}

void	pixel_to_complex(int pixel_x, int pixel_y, t_fractal *f)
{
	 f->zx = (pixel_x - 1920 / 2.0) * 4.0 / 1920;
	f->zy = (pixel_y - 1080 / 2.0) * 4.0 / 1080;
}