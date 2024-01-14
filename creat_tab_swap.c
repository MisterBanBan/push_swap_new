/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:39:11 by afavier           #+#    #+#             */
/*   Updated: 2024/01/11 07:42:22 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_swap(int *tab_a, int count)
{
	int	count_b;
	int	*tab_b;
	int	*tab_y;

	count_b = 0;
	if (error(tab_a, count) == 1)
		return (write(STDERR_FILENO, "Error\n", 6), 0);
	tab_b = malloc(sizeof(int) * count);
	if (!tab_b)
		return (0);
	tab_y = malloc(sizeof(int) * count);
	if (!tab_y)
		return (free(tab_b), 1);
	ft_index(tab_a, tab_y, count);
	if (count == 2)
		two(tab_y);
	if (count > 2)
		swapp(tab_y, tab_b, count, count_b);
	return (free(tab_b), free(tab_y), 0);
}

void	ft_index(int *tab_a, int *tab_y, int count_a)
{
	int	y;
	int	i;
	int	nb;

	y = 0;
	i = 0;
	nb = 0;
	while (count_a > i)
	{
		while (y < count_a)
		{
			if (tab_a[i] > tab_a[y])
				nb++;	
			y++;
		}
		tab_y[i] = nb;
		i++;
		nb = 0;
		y = 0;
	}
}

int	error(int *tab, int count)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (count > i)
	{
		while (count > y)  
		{
			if (tab[i] == tab[y] && tab[i] != ' ')
				return (1);
			y++;
		}
		i++;
		y = i+1;
	}
	return (0);
}
