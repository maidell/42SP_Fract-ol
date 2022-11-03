/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:40:48 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/10/27 00:52:29 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# define WIDTH 800
# define HEIGHT 800
# define TITLE "Fract'ol"
# define REAL 0
# define IMAGINARY 1

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

typedef struct s_fractol
{
	double	min[2];
	double	max[2];
	int		x;
	int		y;
	double	complex[2];
	double	center[2];
}			t_fractol;

#endif