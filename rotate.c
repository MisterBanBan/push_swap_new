/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:15 by afavier           #+#    #+#             */
/*   Updated: 2024/01/11 07:33:30 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(int *tab_a, int count_a)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	c = tab_a[0];
	while (count_a > i + 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	tab_a[i] = c;
	write(1, "ra\n", 3);
}

void	rotate_rb(int *tab_b, int count_b)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	c = tab_b[0];
	while (count_b > i + 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	tab_b[i] = c;
	write(1, "rb\n", 3);
}

void	rotate_rr(int *tab_a, int *tab_b, int count_a, int count_b)
{
	rotate_ra(tab_a, count_a);
	rotate_rb(tab_b, count_b);
	write(1, "rr\n", 3);
}
