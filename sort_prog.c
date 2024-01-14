/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:11:16 by afavier           #+#    #+#             */
/*   Updated: 2024/01/11 08:17:06 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapp(int *tab_a, int *tab_b, int count_a, int count_b)
{
	int	len;
	int	chunk;

	len = count_a;
	chunk = chunks(count_a);
	while (count_b < len - 3)
	{
		if (tab_a[0] <= count_b && tab_a[0] < len - 3)
		{
			push_pb(tab_a, tab_b, count_a, count_b);
			count_a--;
			count_b++;
		}
		else if (tab_a[0] <= chunk + count_b && tab_a[0] < len - 3)
		{
			push_pb(tab_a, tab_b, count_a, count_b);
			count_a--;
			count_b++;
			rotate_rb(tab_b, count_b);
		}
		else
			rotate_ra(tab_a, count_a);
	}
	push_value_a(tab_a, tab_b, count_a, count_b);
}

void	push_value_a(int *tab_a, int *tab_b, int count_a, int count_b)
{
	int	i;

	i = count_b - 1;
	three(tab_a, count_a);
	while (count_b > 0)
	{
		if (tab_b[0] == i)
		{
			push_pa(tab_a, tab_b, count_a, count_b);
			count_a++;
			count_b--;
			i--;
		}
		else if (tab_a[count_a-1] == (count_b + count_a)-1)
		{
			push_pa(tab_a, tab_b, count_a, count_b);
			count_a++;
			count_b--;
			rotate_ra(tab_a, count_a);
		}
		else if (tab_b[0] > tab_a[count_a-1])
		{
			push_pa(tab_a, tab_b, count_a, count_b);
			count_a++;
			count_b--;
			rotate_ra(tab_a, count_a);
		}
		else if (tab_a[count_a-1] == i)
		{
			reverse_rotate_a(tab_a, count_a);
			i--;
		}
		else
			value_top_b(tab_b, count_b,tab_a, count_a);
	}
	while (tab_a[0] != 0)
		reverse_rotate_a(tab_a, count_a);
}

void	value_top_b(int *tab_b, int count_b, int *tab_a, int count_a)
{
	int	y;

	y = 0;
	while (tab_b[y] < tab_a[count_a-1] && count_b > 0)
		y++;
	if (y <= count_b / 2 && count_b > 0)
	{
		while (y > 0 && count_b > 0)
		{
			rotate_rb(tab_b, count_b);
			y--;
		}
	}
	else
	{
		while (y < count_b && count_b > 0)
		{
			reverse_rotate_b(tab_b, count_b);
			y++;
		}
		y = 0;
	}
}

int	chunks(int count)
{
	double	chunks;

	chunks = (0.000000053 * (count * count)) + (0.03 * count) + 14.5;
	return (chunks);
}