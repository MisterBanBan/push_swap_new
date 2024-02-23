/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:32:33 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 10:49:24 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate_ra(t_array *tab_index, t_array *tab_b)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	c = tab_index->tab[0];
	while (tab_index->nb_element > i + 1)
	{
		tab_index->tab[i] = tab_index->tab[i + 1];
		i++;
	}
	tab_index->tab[i] = c;
	if (write(1, "ra\n", 3) == -1)
		free_all(tab_index, tab_b);
}

void	rotate_rb(t_array *tab_index, t_array *tab_b)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	c = tab_b->tab[0];
	while (tab_b->nb_element > i + 1)
	{
		tab_b->tab[i] = tab_b->tab[i + 1];
		i++;
	}
	tab_b->tab[i] = c;
	if (write(1, "rb\n", 3) == -1)
		free_all(tab_index, tab_b);
}

void	rotate_rr(t_array *tab_index, t_array *tab_b)
{
	rotate_ra(tab_index, tab_b);
	rotate_rb(tab_index, tab_b);
	if (write(1, "rr\n", 3) == -1)
		free_all(tab_index, tab_b);
}
