/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allow_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:05:11 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 10:57:44 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	allow_tab(char **argv, t_array *tab_a, int i)
{
	int		j;
	long	n;

	n = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			n = ft_atol(&argv[i][j]);
			if (n == LONG_MAX)
			{
				write(STDERR_FILENO, "Error\n", 6);
				free(tab_a->tab);
				free(tab_a);
				exit(1);
			}
			tab_a->tab[tab_a->nb_element] = n;
			tab_a->nb_element++;
			j = go_following(argv[i], j);
		}
		i++;
	}
	test_if_sort(tab_a);
	return (0);
}

int	go_following(char *argv, int j)
{
	j++;
	while (argv[j] >= '0' && argv[j] <= '9')
		j++;
	while (argv[j] == ' ')
		j++;
	return (j);
}

int	test_if_sort(t_array *tab_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab_a->nb_element > i)
	{
		while (tab_a->nb_element > j)
		{
			if (tab_a->tab[i] >= tab_a->tab[j])
				return (0);
			j++;
		}
		i++;
		j = i +1;
	}
	free(tab_a->tab);
	free(tab_a);
	exit(EXIT_FAILURE);
}
