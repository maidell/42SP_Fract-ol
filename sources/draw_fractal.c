/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:22:08 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/02 23:30:12 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_length + x * (m->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractol(t_mlx *m, t_fractol *f)
{
	t_fractol	teste2;

	f->x = 0;
	teste2.x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			f->center[0] = f->max[0] - f->min[0];
			f->center[1] = f->max[1] - f->min[1];
			f->complex[0] = f->min[0] + ((f->center[0]) * (f->x
						/ (double)WIDTH));
			f->complex[1] = f->min[1] + ((f->center[1]) * (f->y
						/ (double)HEIGHT));
			if (f->fractal(f->complex, 100) == 100)
				my_mlx_pixel_put(m, f->x, f->y, 0xFFF000);
				
			else
				my_mlx_pixel_put(m, f->x, f->y, 0x000000);
			f->y++;
		}
		f->x++;
	}
}
