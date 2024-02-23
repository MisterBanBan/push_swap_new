/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:39:11 by afavier           #+#    #+#             */
/*   Updated: 2024/02/01 13:24:14 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"

int	sort_swap(t_array *tab_a)
{
	t_array	*tab_b;

	error(tab_a);
	tab_b = initialize_array(tab_a->size);
	if (!tab_b)
	{
		free(tab_a->tab);
		free(tab_a);
		exit(EXIT_FAILURE);
	}
	read_get_next(tab_a, tab_b);
	put_checker(tab_a, tab_b);
	return (0);
}

void	read_get_next(t_array *tab_a, t_array *tab_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (read_swap(line, tab_a, tab_b) && read_push(line, tab_a, tab_b)
			&& read_rotate(line, tab_a, tab_b)
			&& read_reverse_rotate(line, tab_a, tab_b))
		{
			free(tab_a->tab);
			free(tab_a);
			free(tab_b->tab);
			free(tab_b);
			free(line);
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

void	error(t_array *tab_a)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (tab_a->nb_element > i)
	{
		while (tab_a->nb_element > y)
		{
			if (tab_a->tab[i] == tab_a->tab[y] && tab_a->tab[i] != ' ')
			{
				write(STDERR_FILENO, "Error\n", 6);
				free(tab_a->tab);
				free(tab_a);
				exit(EXIT_FAILURE);
			}
			y++;
		}
		i++;
		y = i + 1;
	}
}

int	put_checker(t_array *tab_a, t_array *tab_b)
{
	if (is_sorted(tab_a) && (tab_b->nb_element == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(tab_b->tab);
	free(tab_a->tab);
	free(tab_b);
	free(tab_a);
	return (0);
}

bool	is_sorted(t_array *tab_a)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (tab_a->nb_element > i)
	{
		while (tab_a->nb_element > y)
		{
			if (tab_a->tab[i] > tab_a->tab[y])
				return (false);
			y++;
		}
		i++;
		y = i +1;
	}
	return (true);
}
