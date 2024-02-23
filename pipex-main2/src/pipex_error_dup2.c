/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_dup2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:52 by afavier           #+#    #+#             */
/*   Updated: 2024/02/22 16:00:01 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void error_dup2(int *fd, int *fd_cmd)
{
	ft_dprintf(2, "pipex: %s\n", strerror(errno));
	close(fd[0]);
	close(fd[1]);
	close(fd_cmd[0]);
	close(fd_cmd[1]);
	exit(EXIT_FAILURE);
}

void close_files(int *fd, int *fd_cmd)
{
	close(fd[0]);
	close(fd[1]);
	close(fd_cmd[0]);
}
