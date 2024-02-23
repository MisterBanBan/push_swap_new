/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fd_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:54:27 by afavier           #+#    #+#             */
/*   Updated: 2024/02/20 10:34:42 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	number_args(int argc)
{
	if (argc != 5)
	{
		ft_dprintf(2, "pipex: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}
