/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:24 by afavier           #+#    #+#             */
/*   Updated: 2024/02/02 11:25:15 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include "../libft/inc/libft.h"

typedef struct s_array
{
	int	*tab;
	int	nb_element;
	int	size;
}	t_array;

t_array	*initialize_array(int size);
int		allow_tab(char **argv, t_array *tab_a, int i);
int		go_following(char *argv, int y);
long	ft_atol(const char *str);
int		parsing(char **argv, int size, int y, int i);
void	parsing_letter(char *argv, int y);
void	init_sort(t_array *tab_a);
void	error(t_array *tab_a);
void	ft_index(t_array *tab_a, t_array *tab_index);
void	swapp(t_array *tab_index, t_array *tab_b);
void	push_value_a(t_array *tab_index, t_array *tab_b, int i);
void	value_top_b(t_array *tab_index, t_array *tab_b);
int		chunks(int count);
void	push_pa(t_array *tab_index, t_array *tab_b);
void	push_pb(t_array *tab_index, t_array *tab_b);
void	reverse_rotate_a(t_array *tab_index, t_array *tab_b);
void	reverse_rotate_b(t_array *tab_index, t_array *tab_b);
void	reverse_rotate_r(t_array *tab_index, t_array *tab_b);
void	rotate_ra(t_array *tab_index, t_array *tab_b);
void	rotate_rb(t_array *tab_index, t_array *tab_b);
void	rotate_rr(t_array *tab_index, t_array *tab_b);
void	swap_sa(t_array *tab_index, t_array *tab_b);
void	swap_sb(t_array *tab_index, t_array *tab_b);
void	swap_ss(t_array *tab_index, t_array *tab_b);
void	three(t_array *tab_index, t_array *tab_b);
void	finish_push(t_array *tab_index, t_array *tab_b);
void	free_all(t_array *tab_index, t_array *tab_b);
void	free_a_b(t_array *tab_a, t_array *tab_b);
int		test_if_sort(t_array *tab_a);

#endif