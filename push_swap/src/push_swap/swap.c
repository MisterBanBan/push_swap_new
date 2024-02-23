/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:50:09 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 11:02:07 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swapp(t_array *tab_index, t_array *tab_b)
{
	int	len;
	int	chunk;

	len = tab_index->nb_element;
	chunk = chunks(tab_index->nb_element);
	while (tab_b->nb_element < len - 3)
	{
		if (tab_index->tab[0] <= tab_b->nb_element
			&& tab_index->tab[0] < len - 3)
		{
			push_pb(tab_index, tab_b);
		}
		else if (tab_index->tab[0] <= chunk + tab_b->nb_element
			&& tab_index->tab[0] < len - 3)
		{
			push_pb(tab_index, tab_b);
			rotate_rb(tab_index, tab_b);
		}
		else
			rotate_ra(tab_index, tab_b);
	}
	three(tab_index, tab_b);
	push_value_a(tab_index, tab_b, tab_b->nb_element - 1);
}

void	push_value_a(t_array *tab_index, t_array *tab_b, int i)
{
	while (tab_b->nb_element > 0)
	{
		if (tab_b->tab[0] == i)
		{
			push_pa(tab_index, tab_b);
			i--;
		}
		else if ((tab_index->tab[tab_index->nb_element -1]
				== (tab_b->nb_element + tab_index->nb_element) - 1)
			|| (tab_b->tab[0] > tab_index->tab[tab_index->nb_element -1]))
		{
			push_pa(tab_index, tab_b);
			rotate_ra(tab_index, tab_b);
		}
		else if (tab_index->tab[tab_index->nb_element -1] == i)
		{
			reverse_rotate_a(tab_index, tab_b);
			i--;
		}
		else
			value_top_b(tab_index, tab_b);
	}
	finish_push(tab_index, tab_b);
}

void	finish_push(t_array *tab_index, t_array *tab_b)
{
	while (tab_index->tab[0] != 0)
		reverse_rotate_a(tab_index, tab_b);
}

void	value_top_b(t_array *tab_index, t_array *tab_b)
{
	int	y;

	y = 0;
	while (tab_b->nb_element > 0
		&& tab_b->tab[y] < tab_index->tab[tab_index->nb_element -1])
		y++;
	if ((y <= tab_b->nb_element / 2) && (tab_b->nb_element > 0))
	{
		while (y > 0 && tab_b->nb_element > 0)
		{
			rotate_rb(tab_index, tab_b);
			y--;
		}
	}
	else
	{
		while (y < tab_b->nb_element && tab_b->nb_element > 0)
		{
			reverse_rotate_b(tab_index, tab_b);
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
