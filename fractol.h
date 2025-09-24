/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwahab <amwahab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:36:32 by amwahab           #+#    #+#             */
/*   Updated: 2025/09/24 11:48:58 by amwahab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MANDELBROT 1
# define JULIA 2

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
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		fractal_type;
	double	julia_c_real;
	double	julia_c_imag;
}	t_mlx;


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

typedef struct s_mandelbrot
{
	double	c_real;
	double	c_imag;
	double	z_real;
	double		z_imag;
	int		x;
	int		y;
	int		iter;
	int		color;
	int		max_iter;
} t_mandelbrot;

//events
int		handle_close(void *param);
void	exit_fractol(t_mlx *mlx, const char *str);
int		handle_keypress(int keycode, void *params);
int		handle_mouse(int button, int x, int y, t_mlx *mlx);

//fractal
void	fractal(int argc, char **argv, t_mlx *mlx);
//julia
void	draw_julia(t_mlx *mlx, double c_r, double c_i);
//mandelbrot
void	draw_mandelbrot(t_mlx *mlx);
//utils
void	put_pixel_to_image(t_mlx *mlx, int x, int y, int color);
int		get_mandel_color(t_mandelbrot *mandel);
int		get_julia_color(t_julia *julia);

#endif