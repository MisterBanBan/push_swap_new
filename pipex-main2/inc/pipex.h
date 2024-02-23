/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:24 by afavier           #+#    #+#             */
/*   Updated: 2024/02/23 22:20:38 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_dprintf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

char	*find_path(char **env);
void	child(int *fd_cmd, char *path, char **cmd, int *fd, char **env);
char	*find_exec_path(char **argv, char **env, int i);
void	parent(int *fd_cmd, char *path, char **cmd, int *fd, char **env);
int		free_tab(char **tab);
char	*exec_is_good(char **cmd_path, char **cmd, int i);
int		open_fd_child(char **argv);
int		open_fd_parent(char **argv, int fd_child);
void	number_args(int argc);
void error_dup2(int *fd, int *fd_cmd);
void close_files(int *fd, int *fd_cmd);

#endif