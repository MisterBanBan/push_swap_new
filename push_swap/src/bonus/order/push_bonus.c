/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:04:46 by afavier           #+#    #+#             */
/*   Updated: 2024/01/30 14:13:52 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"

void	push_pa(t_array *tab_a, t_array *tab_b)
{
	int	c;
	int	i;
	int	y;

	c = 0;
	i = 0;
	y = 1;
	c = tab_a->tab[0];
	while (tab_a->nb_element > i + 1)
	{
		tab_a->tab[i] = tab_a->tab[y];
		i++;
		y++;
	}
	i = tab_a->nb_element;
	while (i > 0)
	{
		tab_a->tab[i] = tab_a->tab[i - 1];
		i--;
	}
	tab_a->tab[0] = c;
	tab_a->nb_element = tab_a->nb_element + 1;
	tab_b->nb_element = tab_b->nb_element - 1;
}

void	push_pb(t_array *tab_a, t_array *tab_b)
{
	int	c;
	int	i;
	int	y;

	c = 0;
	i = 0;
	y = 1;
	c = tab_a->tab[0];
	while (tab_a->nb_element > i + 1)
	{
		tab_a->tab[i] = tab_a->tab[y];
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
	tab_a->nb_element = tab_a->nb_element - 1;
	tab_b->nb_element = tab_b->nb_element + 1;
}
