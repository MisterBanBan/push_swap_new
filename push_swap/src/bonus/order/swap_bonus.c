/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:03:55 by afavier           #+#    #+#             */
/*   Updated: 2024/01/30 14:47:00 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"

void	swap_sa(t_array *tab_a)
{
	int	c;

	c = tab_a->tab[0];
	tab_a->tab[0] = tab_a->tab[1];
	tab_a->tab[1] = c;
}

void	swap_sb(t_array *tab_b)
{
	int	c;

	c = tab_b->tab[0];
	tab_b->tab[0] = tab_b->tab[1];
	tab_b->tab[1] = c;
}

void	swap_ss(t_array *tab_a, t_array *tab_b)
{
	swap_sa(tab_a);
	swap_sb(tab_b);
}
