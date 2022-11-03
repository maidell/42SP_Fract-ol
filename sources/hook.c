/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:02:22 by coder             #+#    #+#             */
/*   Updated: 2022/11/03 04:13:14 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_zoom(int key, int x, int y, t_data *data)
{
	if (key == 5 && (x || y))
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
	return (0);
}

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	handle_key(int key, t_data *data)
{
	if (key == 65307)
		close_win(data);
	return (0);
}
