/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:26:39 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 11:00:00 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	reverse_rotate_a(t_array *tab_index, t_array *tab_b)
{
	int	c;
	int	nb_element;

	nb_element = tab_index->nb_element -1;
	c = tab_index->tab[nb_element];
	while (nb_element > 0)
	{
		tab_index->tab[nb_element] = tab_index->tab[nb_element - 1];
		nb_element--;
	}
	tab_index->tab[0] = c;
	if (write(1, "rra\n", 4) == -1)
		free_all(tab_index, tab_b);
}

void	reverse_rotate_b(t_array *tab_index, t_array *tab_b)
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
	if (write(1, "rrb\n", 4) == -1)
		free_all(tab_index, tab_b);
}

void	reverse_rotate_r(t_array *tab_index, t_array *tab_b)
{
	reverse_rotate_a(tab_index, tab_b);
	reverse_rotate_b(tab_index, tab_b);
	if (write(1, "rrr\n", 4) == -1)
		free_all(tab_index, tab_b);
}
