/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:06:08 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 10:51:35 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap_sa(t_array *tab_index, t_array *tab_b)
{
	int	c;

	c = tab_index->tab[0];
	tab_index->tab[0] = tab_index->tab[1];
	tab_index->tab[1] = c;
	if (write(1, "sa\n", 3) == -1)
		free_all(tab_index, tab_b);
}

void	swap_sb(t_array *tab_index, t_array *tab_b)
{
	int	c;

	c = tab_b->tab[0];
	tab_b->tab[0] = tab_b->tab[1];
	tab_b->tab[1] = c;
	if (write(1, "sb\n", 3) == -1)
		free_all(tab_index, tab_b);
}

void	swap_ss(t_array *tab_index, t_array *tab_b)
{
	swap_sa(tab_index, tab_b);
	swap_sb(tab_index, tab_b);
	if (write(1, "ss\n", 3) == -1)
		free_all(tab_index, tab_b);
}
