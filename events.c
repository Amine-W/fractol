/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:01:32 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/23 11:44:56 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, void *params)
{
	t_mlx *mlx = (t_mlx *)params;
	
	if(keycode == 65307)
		exit_fractol(mlx, "Escape pressed");
	return (0);
}

int handle_close(void *param)
{
	t_mlx *mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->init, mlx->win);
	mlx_destroy_display(mlx->init);
	free(mlx->init);
	exit(0);
	return (0);
}