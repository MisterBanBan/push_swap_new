/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:48:11 by afavier           #+#    #+#             */
/*   Updated: 2024/01/15 09:48:11 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"

bool	read_swap(char *line, t_array *tab_a, t_array *tab_b)
{
	if (!(ft_strcmp(line, "sa\n")))
	{
		swap_sa(tab_a);
		return (false);
	}
	if (!(ft_strcmp(line, "sb\n")))
	{
		swap_sb(tab_b);
		return (false);
	}
	if (!(ft_strcmp(line, "ss\n")))
	{
		swap_sa(tab_a);
		swap_sb(tab_b);
		return (false);
	}
	return (true);
}

bool	read_push(char *line, t_array *tab_a, t_array *tab_b)
{
	if (!(ft_strcmp(line, "pa\n")))
	{
		if (tab_b->nb_element >= 1)
			push_pa(tab_a, tab_b);
		return (false);
	}
	if (!(ft_strcmp(line, "pb\n")))
	{
		if (tab_a->nb_element >= 1)
			push_pb(tab_a, tab_b);
		return (false);
	}
	return (true);
}

bool	read_rotate(char *line, t_array *tab_a, t_array *tab_b)
{
	if (!(ft_strcmp(line, "ra\n")))
	{
		if (tab_a->nb_element >= 1)
			rotate_ra(tab_a);
		return (false);
	}
	if (!(ft_strcmp(line, "rb\n")))
	{
		if (tab_b->nb_element >= 1)
			rotate_rb(tab_b);
		return (false);
	}
	if (!(ft_strcmp(line, "rr\n")))
	{
		if (tab_b->nb_element >= 1 && tab_a->nb_element >= 1)
			rotate_rr(tab_a, tab_b);
		return (false);
	}
	return (true);
}

bool	read_reverse_rotate(char *line, t_array *tab_a, t_array *tab_b)
{
	if (!(ft_strcmp(line, "rra\n")))
	{
		if (tab_a->nb_element >= 1)
			reverse_rotate_a(tab_a);
		return (false);
	}
	if (!(ft_strcmp(line, "rrb\n")))
	{
		if (tab_b->nb_element >= 1)
			reverse_rotate_b(tab_b);
		return (false);
	}
	if (!(ft_strcmp(line, "rrr\n")))
	{
		if (tab_a->nb_element >= 1 && tab_b->nb_element >= 1)
			reverse_rotate_r(tab_a, tab_b);
		return (false);
	}
	return (true);
}
