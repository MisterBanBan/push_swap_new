/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:35:46 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 10:54:33 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	three(t_array *tab_index, t_array *tab_b)
{
	if (tab_index->tab[0] > tab_index->tab[1]
		&& tab_index->tab[0] > tab_index->tab[2])
	{
		rotate_ra(tab_index, tab_b);
	}
	else if (tab_index->tab[1] > tab_index->tab[0]
		&& tab_index->tab[1] > tab_index->tab[2])
	{
		reverse_rotate_a(tab_index, tab_b);
	}
	if (tab_index->tab[0] > tab_index->tab[1])
	{
		swap_sa(tab_index, tab_b);
	}
}
