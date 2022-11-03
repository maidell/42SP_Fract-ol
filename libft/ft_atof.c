/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 05:15:40 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/07/12 04:37:15 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double    ft_atof(const char *str)
{
    int        sign;
    double    result;
    double    decimal;

    sign = 1;
    result = 0;
    decimal = 0.1;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (ft_isdigit(*str++))
        result *= 10 + (*str - '0');
    while (ft_isdigit(*str))
    {
        result += (*str++ - '0') * decimal;
        decimal /= 10;
    }
    return (result * sign);
}