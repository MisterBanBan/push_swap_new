/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:05:48 by afavier           #+#    #+#             */
/*   Updated: 2024/02/01 13:31:24 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

long	ft_atol(const char *str)
{
	size_t		i;
	int			y;
	long		r;

	i = 0;
	y = 1;
	r = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		y = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		if (((y == -1) && (-r < INT_MIN)) || ((y == 1) && (r > INT_MAX)))
			return (LONG_MAX);
		i++;
	}
	return (r * y);
}
