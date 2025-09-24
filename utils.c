/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:56:22 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/24 11:48:16 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	int offset;

	offset = (y * mlx->line_len) + (x * (mlx->bpp / 8));
	*(unsigned int *)(mlx->img_data + offset) = color;
}
int	get_julia_color(t_julia *julia)
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

int	get_mandel_color(t_mandelbrot *mandel)
{
	int	r;
	int	g;
	int	b;
	
	if(mandel->iter == 100)
		return(0x000000);
	r = (mandel->iter * 9) % 255;
	g = (mandel->iter * 15) % 255;
	b = (mandel->iter * 25) % 255;
	return ((r << 16) | (g << 8) | b);
}
