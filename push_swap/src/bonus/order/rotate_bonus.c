/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:15 by afavier           #+#    #+#             */
/*   Updated: 2024/01/30 14:45:20 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"

void	rotate_ra(t_array *tab_a)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	c = tab_a->tab[0];
	while (tab_a->nb_element > i + 1)
	{
		tab_a->tab[i] = tab_a->tab[i + 1];
		i++;
	}
	tab_a->tab[i] = c;
}

void	rotate_rb(t_array *tab_b)
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
}

void	rotate_rr(t_array *tab_a, t_array *tab_b)
{
	rotate_ra(tab_a);
	rotate_rb(tab_b);
}
