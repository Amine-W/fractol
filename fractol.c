/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:35:25 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/23 12:00:02 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	
	(void)argv;
	(void)argc;
	// if (argc != 2)
	// 	return (0);
	mlx.init = mlx_init();
	
	mlx.win = mlx_new_window(mlx.init, 1920, 1080, "Fractol");
	mlx.img = mlx_new_image(mlx.init, 1920, 1080);
	//fractol()
	mlx_key_hook(mlx.win, handle_keypress, &mlx);
	mlx_hook(mlx.win, 17, 0, handle_close, &mlx);
	mlx_loop(mlx.init);
	mlx_destroy_window(mlx.init, mlx.win);
	mlx_destroy_display(mlx.init);
	return (0);
}