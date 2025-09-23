/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:36:32 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/23 16:15:55 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"


typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	void	*img_data;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_fractal
{
	int	x;
	int	y;
	int	cx;
	int	cy;
	int	zx;
	int	zy;
}	t_fractal;

typedef struct s_julia
{
	double		c_real;
	double		c_imag;
	int			x;
	int			y;
	int			iter;
	int			color;
	int			max_iter;
} t_julia;

//events
int		handle_close(void *param);
void	exit_fractol(t_mlx *mlx, const char *str);
int		handle_keypress(int keycode, void *params);

//fractal
void	fractal(int argc, char **argv, t_mlx *mlx);
//julia
void	draw_julia(t_mlx *mlx, double c_r, double c_i);


#endif