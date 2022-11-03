/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:40:48 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/03 04:23:45 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# define WIDTH 800
# define HEIGHT 800
# define TITLE "Fract'ol"
# define REAL 0
# define IMAGINARY 1
# include "../libft/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min[2];
	double	max[2];
	double	complex[4];
	double	center[2];
	double	constant[2];
	int		(*fractal)(double *complex, int max_i);

}			t_data;

void		draw_fractol(t_data *data);
int			mandelbrot(double *complex, int max_i);
int			julia(double *complex, int max_i);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			close_win(t_data *data);
int			handle_zoom(int key, int x, int y, t_data *data);
int			handle_key(int key, t_data *data);

#endif
