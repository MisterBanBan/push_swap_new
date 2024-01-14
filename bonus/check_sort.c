
int read_swap(char *line,int *tab_a, int *tab_b)
{
	if(!ft_strcmp(line, "sa\n"))
	{
		swap_sa(tab_a);
		return (1);
	}
	if(!ft_strcmp(line, "sb\n"))
	{
		swap_sa(tab_a);
		return (1);
	}
	if(!ft_strcmp(line, "ss\n"))
	{
		swap_sa(tab_a);
		swap_sb(tab_b);
		return (1);
	}
	return (0);
}
int read_push(char *line, int *tab_a, int *tab_b, size_t *count)
{
	if(!ft_strcmp(line, "pa\n"))
	{
		push_pa(tab_a, tab_b, count[0], count[1]);
		count[0] = count[0] + 1;
		count[1] = count[1] - 1;
		return (1);
	}
	if(!ft_strcmp(line, "pb\n"))
	{
		push_pb(tab_a, tab_b, count[0], count[1]);
		count[0] = count[0] - 1;
		count[1] = count[1] + 1;
		return (1);
	}
}
int read_rotate(char *line, int *tab_a, int *tab_b, size_t *count)
{
	if(!ft_strcmp(line, "ra\n"))
	{
		rotate_ra(tab_a, count[0]);
		return (1);
	}
	if(!ft_strcmp(line, "rb\n"))
	{
		rotate_ra(tab_b, count[1]);
		return (1);
	}
	if(!ft_strcmp(line, "rr\n"))
	{
		rotate_rr(tab_a, tab_b, count[0], count_b[1]);
		return (1);
	}
}
int read_reverse_rotate(char *line, int *tab_a, int *tab_b, size_t *count)
{
	if(!ft_strcmp(line, "rra\n"))
	{
		reverse_rotate_a(tab_a, count[0]);
		return (1);
	}
	if(!ft_strcmp(line, "rrb\n"))
	{
		reverse_rotate_b(tab_b, count[0]);
		return (1);
	}
	if(!ft_strcmp(line, "rrr\n"))
	{
		reverse_rotate_r(tab_a, tab_b, count[0], count[1]);
		return (1);
	}
}
int put_checker(int *tab_a, int *tab_b, size_t *count)
{
	if (is_sorted(tab_a, count[0]))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
}
int	is_sorted(int *tab, size_t *count)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (count[0] > i)
	{
		while (count[0] > y)
		{
			if (tab[i] > tab[y])
				return (1);
			y++;
		}
		i++;
		y = i+1;
	}
	return (0);
}