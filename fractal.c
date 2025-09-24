/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:26:59 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/24 11:29:20 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal(int argc, char **argv, t_mlx *mlx)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	 {
		mlx->fractal_type = MANDELBROT;
		draw_mandelbrot(mlx);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			exit_fractol(mlx, "Invalid Julia parameters");
		mlx->fractal_type = JULIA;
		mlx->julia_c_real = atof(argv[2]);
		mlx->julia_c_imag = atof(argv[3]);
		draw_julia(mlx, mlx->julia_c_real, mlx->julia_c_imag);
	}
	else
	{
		ft_printf("Unknown fractal: %s\n", argv[1]);
		ft_printf("Available: mandelbrot, julia\n");
		exit_fractol(mlx, "Invalid fractal type");
	}
}
