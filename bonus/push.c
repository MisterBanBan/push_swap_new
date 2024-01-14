/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:04:46 by afavier           #+#    #+#             */
/*   Updated: 2024/01/11 07:32:42 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pa(int *tab_a, int *tab_b, size_t *count)
{
	int	c;
	size_t 	i;
	size_t 	y;

	c = 0;
	i = 0;
	y = 1;
	c = tab_b[0];
	while (count[1] > y)
	{
		tab_b[i] = tab_b[y];
		i++;
		y++;
	}
	y = count[0];
	while (y > 0)
	{
		tab_a[y] = tab_a[y - 1];
		y--;
	}
	tab_a[0] = c;
}

void	push_pb(int *tab_a, int *tab_b, size_t *count)
{
	int		c;
	size_t 	i;
	size_t 	y;

	c = 0;
	i = 0;
	y = 1;
	c = tab_a[0];
	while (count[0] > i + 1)
	{
		tab_a[i] = tab_a[y];
		i++;
		y++;
	}
	y = count[1];
	while (y > 0)
	{
		tab_b[y] = tab_b[y - 1];
		y--;
	}
	tab_b[0] = c;
}
