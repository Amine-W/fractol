/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:36:32 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/23 11:47:18 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>
# include "minilibx-linux/mlx.h"
#include "ft_printf/ft_printf.h"


typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}	t_mlx;

// typedef struct s_mandelbrot
// {
	
// } t_mandelbrot;

//events
int		handle_close(void *param);
void	exit_fractol(t_mlx *mlx, const char *str);
int	handle_keypress(int keycode, void *params);


#endif