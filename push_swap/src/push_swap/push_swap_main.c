/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:53:22 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 11:12:58 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	t_array	*tab_a;

	if (argc < 2)
		return (EXIT_FAILURE);
	size = parsing(argv, 0, 0, 1);
	if (size == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (0);
	}
	tab_a = initialize_array(size);
	if (!tab_a)
		exit(EXIT_FAILURE);
	allow_tab(argv, tab_a, 1);
	init_sort(tab_a);
	return (0);
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

int	parsing(char **argv, int size, int j, int i)
{
	while (argv[i])
	{
		while (argv[i][j])
		{
			parsing_letter(argv[i], j);
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				size = size + 1;
				while (argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
				while (argv[i][j] == ' ' && argv[i][j])
					j++;
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (size);
}

void	parsing_letter(char *argv, int j)
{
	if (argv[j] == '-' && ((!(argv[j +1] <= '9' && argv[j +1] >= '0')
				|| (j != 0 && argv[j -1] != ' ')) || argv[j +1] == '\0'))
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if ((!(argv[j] <= '9' && argv[j] >= '0') && argv[j] != ' ' )
		&& argv[j] != '-')
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
