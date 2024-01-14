/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:44 by afavier           #+#    #+#             */
/*   Updated: 2024/01/11 07:33:10 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(int *tab_a, int count_a)
{
	int	c;

	c = 0;
	count_a--;
	c = tab_a[count_a];
	while (count_a > 0)
	{
		tab_a[count_a] = tab_a[count_a - 1];
		count_a--;
	}
	tab_a[0] = c;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(int *tab_b, int count_b)
{
	int	c;

	count_b--;
	c = tab_b[count_b];
	while (count_b > 0)
	{
		tab_b[count_b] = tab_b[count_b - 1];
		count_b--;
	}
	tab_b[0] = c;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_r(int *tab_a, int *tab_b, int count_a, int count_b)
{
	reverse_rotate_a(tab_a, count_a);
	reverse_rotate_b(tab_b, count_b);
	write(1, "rrr\n", 4);
}
