/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:02:22 by coder             #+#    #+#             */
/*   Updated: 2022/11/03 08:03:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_zoom (int key, int x , int y, t_data *data)
{
    
    // x= 1.1;
    // y= 0.9;
    
	if(key == 5 && (x || y))
    {
        data->max[0] *= 1.1;
        data->min[0] *= 1.1;
        data->max[1] *= 1.1;
        data->min[1] *= 1.1;
    }
    else if (key == 4 && (x || y))
    {
        data->max[0] *= 0.9;
        data->min[0] *= 0.9;
        data->max[1] *= 0.9;
        data->min[1] *= 0.9;
    }
    draw_fractol(data);
    return 0;
}

int close_win (t_data *data)
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
}
