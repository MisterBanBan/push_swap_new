/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:13:35 by afavier           #+#    #+#             */
/*   Updated: 2024/01/11 08:06:52 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

int		atoi(const char *str);
void	two(int *tab);
void	three(int *tab, int count_a);
int		read_swap(char *line,int *tab_a, int *tab_b);
int		read_push(char *line, int *tab_a, int *tab_b, size_t *count)
int		read_rotate(char *line, int *tab_a, int *tab_b, size_t *count)
int		read_reverse_rotate(char *line, int *tab_a, int *tab_b, size_t *count)
int		put_checker(int *tab_a, int *tab_b, size_t *count)
int		is_sorted(int *tab, size_t *count)
void	swap_sa(int *tab_a);
void	swap_sb(int *tab_b);
void	swap_ss(int *tab_a, int *tab_b);
void	push_pa(int *tab_a, int *tab_b, int count_a, int count_b);
void	push_pb(int *tab_a, int *tab_b, int count_a, int count_b);
void	rotate_ra(int *tab_a, int count_a);
void	rotate_rb(int *tab_b, int count_b);
void	rotate_rr(int *tab_a, int *tab_b, int count_a, int count_b);
void	reverse_rotate_a(int *tab_a, int count_a);
void	reverse_rotate_b(int *tab_b, int count_b);
void	reverse_rotate_r(int *tab_a, int *tab_b, int count_a, int count_b);
void	swapp(int *tab_a, int *tab_b, int count_a, int count_b);
int		sort_swap(int *tab_a, int count);
int		parsing(char *argv, int count, int y);
int		allow_tab(char *argv, int *tab_a, int x);
int		error(int *tab, int count);

#endif