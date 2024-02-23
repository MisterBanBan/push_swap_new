/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:52:53 by afavier           #+#    #+#             */
/*   Updated: 2024/02/24 00:07:17 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <sys/wait.h>

int	main(int argc, char **argv, char **env)
{
	int		fd_cmd[2];
	int		fd[2];
	char	*path;
	char **cmd;
	
	number_args(argc);
	fd[0] = open_fd_child(argv);
	fd[1] = open_fd_parent(argv, fd[0]);
	if (pipe(fd_cmd) == -1)
	{
		ft_dprintf(2, "pipex: %s\n",strerror(errno));
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	path = find_exec_path(argv, env, 2);
	if (!path)
	{
		close(fd_cmd[1]);
		ft_dprintf(2, "pipex: %s: command not found\n", argv[2]);
	}
	else
	{
		cmd = ft_split(argv[2], ' ');
		if (!cmd)
			free(path);
		else
		{
			child(fd_cmd, path, cmd, fd, env);
			free(path);
			free_tab(cmd);
		}
	}
	path = find_exec_path(argv, env, 3);
	if (!path)
		ft_dprintf(2, "pipex: %s: command not found\n", argv[3]);
	else
	{
		cmd = ft_split(argv[3], ' ');
		if (!cmd)
		{
			free(path);
			return (-1);
		}
		else
		{
			parent(fd_cmd, path, cmd, fd, env);
			free(path);
			free_tab(cmd);
		}
	}
	while (wait(NULL) > 0)
		;
	close(fd[0]);
	close(fd[1]);
	close(fd_cmd[0]);
	close(fd_cmd[1]);
	return (0);
}

void	child(int *fd_cmd, char *path, char **cmd, int *fd, char **env)
{
	pid_t	pid;
	
	pid = fork();
	if (pid == -1)
		error_dup2(fd, fd_cmd);
	if (pid == 0)
	{
		if (fd[0] < 0)
			error_dup2(fd, fd_cmd);
		if (dup2(fd_cmd[1], STDOUT_FILENO) == -1)
			error_dup2(fd, fd_cmd);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			error_dup2(fd, fd_cmd);
		close_files(fd, fd_cmd);
		if (close(fd_cmd[1]) == -1)
		{
			ft_dprintf(2, "pipex: %d: %s\n", fd_cmd[1], strerror(errno));
			exit(EXIT_FAILURE);
		}
		if (execve(path, cmd, env) == -1)
		{
			close(0);
			close(1);
			exit(127);
		}
	}
	else
	{
		if (close(fd_cmd[1]) == -1)
		{
			close(fd[0]);
			close(fd[1]);
			close(fd_cmd[0]);
			exit(EXIT_FAILURE);
		}
	}
}

void	parent(int *fd_cmd, char *path, char **cmd, int *fd, char **env)
{
	pid_t	pid;
	
	pid = fork();
	if (pid == -1)
	{
		ft_dprintf(2, "pipex: %s\n", strerror(errno));
		close_files(fd, fd_cmd);
	}
	if (pid == 0)
	{
		if (dup2(fd_cmd[0], STDIN_FILENO) == -1)
			error_dup2(fd, fd_cmd);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error_dup2(fd, fd_cmd);
		close_files(fd, fd_cmd);
		if (execve(path, cmd, env) == -1)
		{
			close(0);
			close(1);
			exit(127);
		}
	}
	else
	{
		if (close(fd_cmd[0]) == -1)
		{
			close(fd[0]);
			close(fd[1]);
			exit(EXIT_FAILURE);
		}
	}
}
