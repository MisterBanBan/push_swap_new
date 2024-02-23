/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:44 by afavier           #+#    #+#             */
/*   Updated: 2024/02/01 13:24:27 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"

void	reverse_rotate_a(t_array *tab_a)
{
	int	c;
	int	nb_element;

	nb_element = tab_a->nb_element -1;
	c = tab_a->tab[nb_element];
	while (nb_element > 0)
	{
		tab_a->tab[nb_element] = tab_a->tab[nb_element - 1];
		nb_element--;
	}
	tab_a->tab[0] = c;
}

void	reverse_rotate_b(t_array *tab_b)
{
	int	c;
	int	nb_element;

	nb_element = tab_b->nb_element -1;
	c = tab_b->tab[nb_element];
	while (nb_element > 0)
	{
		tab_b->tab[nb_element] = tab_b->tab[nb_element - 1];
		nb_element--;
	}
	tab_b->tab[0] = c;
}

void	reverse_rotate_r(t_array *tab_a, t_array *tab_b)
{
	reverse_rotate_a(tab_a);
	reverse_rotate_b(tab_b);
}
