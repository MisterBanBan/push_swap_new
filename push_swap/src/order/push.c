/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:09:03 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 11:33:32 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_pa(t_array *tab_index, t_array *tab_b)
{
	int	c;
	int	i;
	int	y;

	c = 0;
	i = 0;
	y = 1;
	c = tab_b->tab[0];
	while (tab_b->nb_element > i + 1)
	{
		tab_b->tab[i] = tab_b->tab[y];
		i++;
		y++;
	}
	i = tab_index->nb_element;
	while (i > 0)
	{
		tab_index->tab[i] = tab_index->tab[i - 1];
		i--;
	}
	tab_index->tab[0] = c;
	tab_index->nb_element = tab_index->nb_element + 1;
	tab_b->nb_element = tab_b->nb_element - 1;
	if (write(1, "pa\n", 3) == -1)
		free_all(tab_index, tab_b);
}

void	push_pb(t_array *tab_index, t_array *tab_b)
{
	int	c;
	int	i;
	int	y;

	c = 0;
	i = 0;
	y = 1;
	c = tab_index->tab[0];
	while (tab_index->nb_element > i + 1)
	{
		tab_index->tab[i] = tab_index->tab[y];
		i++;
		y++;
	}
	i = tab_b->nb_element;
	while (i > 0)
	{
		tab_b->tab[i] = tab_b->tab[i - 1];
		i--;
	}
	tab_b->tab[0] = c;
	tab_index->nb_element = tab_index->nb_element - 1;
	tab_b->nb_element = tab_b->nb_element + 1;
	if (write(1, "pb\n", 3) == -1)
		free_all(tab_index, tab_b);
}
