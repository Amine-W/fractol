/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:19:33 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/24 15:52:45 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burningship_iteration(t_burningship *burn, t_mlx *mlx)
{
	double	temp;

	burn->z_real = 0.0;
	burn->z_imag = 0.0;
	burn->c_real = (burn->x - 350.0) / mlx->zoom + mlx->offset_x;
	burn->c_imag = (burn->y - 350.0) / mlx->zoom + mlx->offset_y;
	burn->iter = 0;
	while (burn->iter < 100 && (burn->z_real * burn->z_real
			+ burn->z_imag * burn->z_imag) < 4.0)
	{
		temp = (burn->z_real * burn->z_real)
			- burn->z_imag * burn->z_imag + burn->c_real;
		burn->z_imag = 2 * fabs
			(burn->z_real) * fabs(burn->z_imag) + burn->c_imag;
		burn->z_real = temp;
		burn->iter++;
	}
	return (burn->iter);
}

void	draw_burningship(t_mlx *mlx)
{
	t_burningship	burn;

	burn.max_iter = 100;
	burn.y = -1;
	while (++burn.y < 700)
	{
		burn.x = -1;
		while (++burn.x < 700)
		{
			burningship_iteration(&burn, mlx);
			burn.color = get_burningship_color(&burn);
			put_pixel_to_image(mlx, burn.x, burn.y, burn.color);
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}
