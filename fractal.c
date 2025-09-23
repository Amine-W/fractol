/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:26:59 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/23 16:14:24 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal(int argc, char **argv, t_mlx *mlx)
{
	double	c_r;
	double	c_i;
	
	// if (ft_strcmp(argv[1], "mandelbrot") == 0)
	// 	draw_mandelbrot(mlx);
	/* else */if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			exit_fractol(mlx, "Invalid Julia parameters");
		c_r = atof(argv[2]);
		c_i = atof(argv[3]);
		draw_julia(mlx, c_r, c_i);
	}
	else
	{
		ft_printf("Unknown fractal: %s\n", argv[1]);
		ft_printf("Available: mandelbrot, julia\n");
		exit_fractol(mlx, "Invalid fractal type");
	}
}
