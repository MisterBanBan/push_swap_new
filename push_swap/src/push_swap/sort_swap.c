/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:34:04 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 11:23:45 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	init_sort(t_array *tab_a)
{
	t_array	*tab_b;
	t_array	*tab_index;

	error(tab_a);
	tab_b = initialize_array(tab_a->size);
	if (!tab_b)
	{
		free(tab_a->tab);
		free(tab_a);
		exit(EXIT_FAILURE);
	}
	tab_index = initialize_array(tab_a->size);
	if (!tab_index)
		free_a_b(tab_a, tab_b);
	ft_index(tab_a, tab_index);
	free(tab_a->tab);
	free(tab_a);
	if (tab_index->nb_element == 2)
	{
		if (tab_index->tab[0] > tab_index->tab[1])
			swap_sa(tab_index, tab_b);
	}
	if (tab_index->size > 2)
		swapp(tab_index, tab_b);
	free_all(tab_index, tab_b);
}

void	error(t_array *tab_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab_a->nb_element > i)
	{
		while (tab_a->nb_element > j)
		{
			if (tab_a->tab[i] == tab_a->tab[j])
			{
				write(STDERR_FILENO, "Error\n", 6);
				free(tab_a->tab);
				free(tab_a);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	ft_index(t_array *tab_a, t_array *tab_index)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (tab_a->nb_element > tab_index->nb_element)
	{
		while (i < tab_a->nb_element)
		{
			if (tab_a->tab[tab_index->nb_element] > tab_a->tab[i])
				nb++;
			i++;
		}
		tab_index->tab[tab_index->nb_element] = nb;
		tab_index->nb_element++;
		nb = 0;
		i = 0;
	}
}

void	free_all(t_array *tab_index, t_array *tab_b)
{
	free(tab_index->tab);
	free(tab_index);
	free(tab_b->tab);
	free(tab_b);
	exit(EXIT_FAILURE);
}

void	free_a_b(t_array *tab_a, t_array *tab_b)
{
	free(tab_a->tab);
	free(tab_a);
	free(tab_b->tab);
	free(tab_b);
	exit(EXIT_FAILURE);
}
