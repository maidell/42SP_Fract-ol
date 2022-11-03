/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:35:41 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/03 04:44:03 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *data)
{
	data->min[REAL] = -1.5;
	data->max[REAL] = 1.5;
	data->min[IMAGINARY] = -1.5;
	data->max[IMAGINARY] = 1.5;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	error_argument(int err)
{
	if (err == 1)
	{
		ft_putstr_fd("\033[0;31mError: Missing argument or invite number\n", 1);
		ft_putstr_fd("\033[0;35mif you are using Julia fractal, you must\n", 1);
		ft_putstr_fd("add the complex number as a second argument\n", 1);
		ft_putstr_fd("\033[0;37mExample: ./fractol Julia -0.4 0.6\n", 1);
	}
	else if (err == 2)
	{
		ft_putstr_fd("\033[0;31mError: Invalid fractal name\n", 1);
		ft_putstr_fd("\033[0;35mAvailable fractals\n", 1);
		ft_putstr_fd("./fractol mandelbrot\n./fractol julia [number]"
				" [number]\n", 1);
	}
	exit(EXIT_FAILURE);
}

void	handle_args(int argc, char **argv, t_data *data)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		data->fractal = mandelbrot;
	else if (argc >= 2 && !ft_strncmp(argv[1], "julia", 10))
	{
		data->fractal = julia;
		if (argc == 4 && ft_isnumber(argv[2]) && ft_isnumber(argv[3]))
		{
			data->complex[2] = ft_atof(argv[2]);
			data->complex[3] = ft_atof(argv[3]);
		}
		else
			error_argument(1);
	}
	else
		error_argument(2);
}

int	main(int argc, char **argv)
{
	t_data	data;

	handle_args(argc, argv, &data);
	init_data(&data);
	draw_fractol(&data);
	mlx_mouse_hook(data.win, handle_zoom, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
}
