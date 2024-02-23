/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:27:52 by afavier           #+#    #+#             */
/*   Updated: 2024/02/01 13:22:38 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		size;
	t_array	*tab_a;

	if (argc < 2)
		return (0);
	size = parsing(argv, 0, 0, 1);
	if (size == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (0);
	}
	tab_a = initialize_array(size);
	if (!tab_a)
		exit(1);
	allow_tab(argv, tab_a, 1);
	sort_swap(tab_a);
	return (0);
}

int	allow_tab(char **argv, t_array *tab_a, int i)
{
	int		y;
	long	n;

	y = 0;
	n = 0;
	while (argv[i])
	{
		while (argv[i][y])
		{
			n = ft_atol(&argv[i][y]);
			if (n == LONG_MAX)
			{
				write(STDERR_FILENO, "Error\n", 6);
				free(tab_a->tab);
				free(tab_a);
				exit(1);
			}
			tab_a->tab[tab_a->nb_element] = n;
			tab_a->nb_element++;
			y = go_following(argv[i], y);
		}
		y = 0;
		i++;
	}
	return (0);
}

int	go_following(char *argv, int y)
{
	y++;
	if (argv[y] >= '0' && argv[y] <= '9')
	{
		while (argv[y] >= '0' && argv[y] <= '9')
			y++;
		while ((argv[y] < '0' || argv[y] > '9') && argv[y]
			&& argv[y] != '-')
			y++;
	}
	return (y);
}

t_array	*initialize_array(int size)
{
	t_array	*new_array;

	new_array = malloc(sizeof(t_array));
	if (!new_array)
		return (NULL);
	new_array->tab = malloc(sizeof(int) * size);
	if (!new_array->tab)
		return (free(new_array), NULL);
	new_array->nb_element = 0;
	new_array->size = size;
	return (new_array);
}
