/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:01:43 by afavier           #+#    #+#             */
/*   Updated: 2024/02/01 13:16:43 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"

long	ft_atol(const char *str)
{
	unsigned int	i;
	int				y;
	long int		r;

	i = 0;
	y = 1;
	r = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' '
		|| str[i] == '"')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			y = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		if (((y == -1) && (-r <= INT_MIN)) || ((y == 1) && (r >= INT_MAX)))
			return (LONG_MAX);
		i++;
	}
	return (r * y);
}
