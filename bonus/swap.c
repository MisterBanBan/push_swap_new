/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:03:55 by afavier           #+#    #+#             */
/*   Updated: 2024/01/11 07:40:25 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(int *tab_a)
{
	int	c;

	c = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = c;
}

void	swap_sb(int *tab_b)
{
	int	c;

	c = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = c;
}

void	swap_ss(int *tab_a, int *tab_b)
{
	swap_sa(tab_a);
	swap_sb(tab_b);
}
