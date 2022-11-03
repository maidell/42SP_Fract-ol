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

int random_color (int i)
{
    int    rbg[3];

    rbg[0] = sin(0.1 * i + 5) * 127 + 128;
    rbg[1] = sin(0.1 * i + 6) * 127 + 128;
    rbg[2] = sin(0.1 * i + 7) * 127 + 128;
    return (rbg[0] << 16 | rbg[1] << 8 | rbg[2]);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    draw_fractol(t_data *data)
{
    int     axle[2];
    int     result;

    axle[0] = 0;
    while (axle[0] < WIDTH)
    {
        axle[1] = 0;
        while (axle[1] < HEIGHT)
        {
            data->center[0] = data->max[0] - data->min[0];
            data->center[1] = data->max[1] - data->min[1];
            data->complex[0] = data->min[0] + ((data->center[0]) * (axle[0]
                        / (double)WIDTH));
            data->complex[1] = data->min[1] + ((data->center[1]) * (axle[1]
                        / (double)HEIGHT));
            result = data->fractal(data->complex, 100);
            if (result == 100)
                my_mlx_pixel_put(data, axle[0], axle[1], 0x000000);
            else
                my_mlx_pixel_put(data, axle[0], axle[1], random_color(result));
            axle[1]++;
        }
        axle[0]++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}