/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:13:35 by afavier           #+#    #+#             */
/*   Updated: 2024/02/01 13:09:58 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdbool.h>
# include "../libft/inc/get_next_line.h"

typedef struct s_array
{
	int	*tab;
	int	nb_element;
	int	size;
}	t_array;

t_array	*initialize_array(int size);
long	ft_atol(const char *str);
bool	read_swap(char *line, t_array *tab_a, t_array *tab_b);
bool	read_push(char *line, t_array *tab_a, t_array *tab_b);
bool	read_rotate(char *line, t_array *tab_a, t_array *tab_b);
bool	read_reverse_rotate(char *line, t_array *tab_a, t_array *tab_b);
int		put_checker(t_array *tab_a, t_array *tab_b);
bool	is_sorted(t_array *tab_a);
void	swap_sa(t_array *tab_a);
void	swap_sb(t_array *tab_b);
void	swap_ss(t_array *tab_a, t_array *tab_b);
void	push_pa(t_array *tab_a, t_array *tab_b);
void	push_pb(t_array *tab_a, t_array *tab_b);
void	rotate_ra(t_array *tab_a);
void	rotate_rb(t_array *tab_b);
void	rotate_rr(t_array *tab_a, t_array *tab_b);
void	reverse_rotate_a(t_array *tab_a);
void	reverse_rotate_b(t_array *tab_b);
void	reverse_rotate_r(t_array *tab_a, t_array *tab_b);
int		sort_swap(t_array *tab_a);
int		parsing(char **argv, int size, int y, int i);
void	parsing_letter(char *argv, int y);
int		allow_tab(char **argv, t_array *tab_a, int i);
void	error(t_array *tab_a);
int		ft_strcmp(const char *s1, const char *s2);
int		go_following(char *argv, int y);
void	read_get_next(t_array *tab_a, t_array *tab_b);

#endif