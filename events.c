/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:01:32 by amwahab           #+#    #+#             */
/*   Updated: 2025/10/01 10:21:18 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_arrows(int keycode, t_mlx *mlx)
{
	double	move_step;

	move_step = 10.0 / mlx->zoom;
	if (keycode == 65361)
		mlx->offset_x -= move_step;
	else if (keycode == 65363)
		mlx->offset_x += move_step;
	else if (keycode == 65362)
		mlx->offset_y -= move_step;
	else if (keycode == 65364)
		mlx->offset_y += move_step;
	redraw_fractal(mlx);
}

int	handle_keypress(int keycode, void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	if (keycode == 65307)
		exit_fractol(mlx, "Escape pressed");
	else if (keycode >= 65361 && keycode <= 65364)
		handle_arrows(keycode, mlx);
	else if (keycode == 113)
	{
		if (mlx->iter_count > 0)
			mlx->iter_count -= 10;
		redraw_fractal(mlx);
	}
	else if (keycode == 101)
	{
		if (mlx->iter_count < 500)
			mlx->iter_count += 10;
		redraw_fractal(mlx);
	}
	return (0);
}

int	handle_close(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	exit_fractol(mlx, "Window closed");
	return (0);
}
