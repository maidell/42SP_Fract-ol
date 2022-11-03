/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractais.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:18:30 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/02 23:34:22 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double *complex)
{
	double	number[4];
	int		index;

	index = 0;
	number[3] = 0;
	number[0] = complex[0];
	number[1] = complex[1];
	while ((index < 100) && (number[3] < 4.0))
	{
		number[2] = pow(number[0], 2) - pow(number[1], 2) + complex[0];
		number[1] = 2 * number[0] * number[1] + complex[1];
		number[0] = number[2];
		number[3] = pow(number[0], 2) + pow(number[1], 2);
		index++;
	}
	return (index);
}

int	julia(double *complex)
{
	double	number[4];
	int		index;

	index = 0;
	number[3] = 0;
	number[0] = complex[0];
	number[1] = complex[1];
	while ((index < 100) && (number[3] < 4.0))
	{
		number[2] = pow(number[0], 2) - pow(number[1], 2) + complex[2];
		number[1] = 2 * number[0] * number[1] + complex[3];
		number[0] = number[2];
		number[3] = pow(number[0], 2) + pow(number[1], 2);
		index++;
	}
	return (index);
}