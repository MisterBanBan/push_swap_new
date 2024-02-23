/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:48:31 by afavier           #+#    #+#             */
/*   Updated: 2024/02/23 16:04:38 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	open_fd_child(char **argv)
{
	int	fd_child;

	fd_child = open(argv[1], O_RDONLY);
	if (fd_child < 0)
		ft_dprintf(2, "pipex: %s: %s\n", argv[1], strerror(errno));
	return (fd_child);
}

int	open_fd_parent(char **argv, int fd_child)
{
	int	fd_parent;

	fd_parent = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_parent < 0)
	{
		close(fd_child);
		ft_dprintf(2, "pipex: %s: %s\n", argv[4], strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd_parent);
}

