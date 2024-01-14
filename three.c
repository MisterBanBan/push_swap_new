/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 08:56:40 by afavier           #+#    #+#             */
/*   Updated: 2024/01/11 07:30:55 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(int *tab, int count_a)
{
	if (tab[0] > tab[1] && tab[0] > tab[2])
	{
		rotate_ra(tab, count_a);
	}
	else if (tab[1] > tab[0] && tab[1] > tab[2])
	{
		reverse_rotate_a(tab, count_a);
	}
	if (tab[0] > tab[1])
	{
		swap_sa(tab);
	}
}
