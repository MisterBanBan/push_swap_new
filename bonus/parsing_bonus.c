/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:30:03 by afavier           #+#    #+#             */
/*   Updated: 2024/01/11 07:31:33 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(char *argv, int count, int y)
{
	while (argv[y])
	{
		if (argv[y] == '-' && (!(argv[y +1] <= '9' && argv[y +1] >= '0')
				|| argv[y +1] == '\0'))
			return (write(STDERR_FILENO, "Error\n", 6), 0);
		if ((!(argv[y] <= '9' && argv[y] >= '0') && argv[y] != ' ' )
			&& argv[y] != '-')
			return (write(STDERR_FILENO, "Error\n", 6), 0);
		if (argv[y] >= '0' && argv[y] <= '9')
		{
			count++;
			while (argv[y] >= '0' && argv[y] <= '9')
				y++;
			while (argv[y] == ' ' && argv[y])
				y++;
		}
		else
			y++;
	}
	return (count);
}
