/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:05:40 by afavier           #+#    #+#             */
/*   Updated: 2024/01/09 16:47:37 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	y;
	int	count;
	int	*tab_a;

	i = 1;
	y = 0;
	count = 0;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		if (parsing(argv[i], count, y) == 0)
			return (0);
		count = parsing(argv[i++], count, y);
	}
	tab_a = malloc(sizeof(int) * count);
	if (!tab_a)
		return (0);
	i = 1;
	while (argv[i])
		y = allow_tab(argv[i++], tab_a, y);
	sort_swap(tab_a, count);
	return (free(tab_a), 0);
}

int	allow_tab(char *argv, int *tab_a, int x)
{
	int	y;

	y = 0;
	while (argv[y])
	{
		tab_a[x] = ft_atoi(&argv[y]);
		y++;
		if (argv[y] >= '0' && argv[y] <= '9')
		{
			while (argv[y] >= '0' && argv[y] <= '9')
				y++;
			while ((argv[y] < '0' || argv[y] > '9') && argv[y]
				&& argv[y] != '-')
				y++;
		}
		x++;
	}
	return (x);
}
