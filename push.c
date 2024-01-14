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

void	push_pa(int *tab_a, int *tab_b, int count_a, int count_b)
{
	int	c;
	int	i;
	int	y;

	c = 0;
	i = 0;
	y = 1;
	c = tab_b[0];
	while (count_b > y)
	{
		tab_b[i] = tab_b[y];
		i++;
		y++;
	}
	while (count_a > 0)
	{
		tab_a[count_a] = tab_a[count_a - 1];
		count_a--;
	}
	tab_a[0] = c;
	write(1, "pa\n", 3);
}

void	push_pb(int *tab_a, int *tab_b, int count_a, int count_b)
{
	int	c;
	int	i;
	int	y;

	c = 0;
	i = 0;
	y = 1;
	c = tab_a[0];
	while (count_a > i + 1)
	{
		tab_a[i] = tab_a[y];
		i++;
		y++;
	}
	while (count_b > 0)
	{
		tab_b[count_b] = tab_b[count_b - 1];
		count_b--;
	}
	tab_b[0] = c;
	write(1, "pb\n", 3);
}
