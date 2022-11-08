/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:10:59 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/08 06:10:44 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(const char *s)
{
	int	verify;

	verify = 0;
	if (((*s == '-') || (*s == '+')) && !ft_isdigit(*(s + 1)))
		return (0);
	if (s[ft_strlen(s) - 1] == '.')
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '.')
		return (0);
	while (*s)
	{
		if (*s == '.')
			verify++;
		if (verify > 1)
			return (0);
		if (!ft_isdigit(*s) && *s != '.' && *s)
			return (0);
		s++;
	}
	return (1);
}
