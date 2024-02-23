/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:30:03 by afavier           #+#    #+#             */
/*   Updated: 2024/02/01 13:19:19 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"

int	parsing(char **argv, int size, int y, int i)
{
	while (argv[i])
	{
		while (argv[i][y])
		{
			parsing_letter(argv[i], y);
			if (argv[i][y] >= '0' && argv[i][y] <= '9')
			{
				size = size + 1;
				while (argv[i][y] >= '0' && argv[i][y] <= '9')
					y++;
				while (argv[i][y] == ' ' && argv[i][y])
					y++;
			}
			else
				y++;
		}
		y = 0;
		i++;
	}
	return (size);
}

void	parsing_letter(char *argv, int y)
{
	if (argv[y] == '-' && ((!(argv[y +1] <= '9' && argv[y +1] >= '0')
				|| (y != 0 && argv[y -1] != ' ')) || argv[y +1] == '\0'))
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if ((!(argv[y] <= '9' && argv[y] >= '0') && argv[y] != ' ' )
		&& argv[y] != '-')
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
