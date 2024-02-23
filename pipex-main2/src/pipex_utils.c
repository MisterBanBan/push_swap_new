/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 06:02:12 by afavier           #+#    #+#             */
/*   Updated: 2024/02/23 23:30:53 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH", env[i], 4))
		{
			return (env[i] + 5);
		}
		i++;
	}
	return (NULL);
}

char	*find_exec_path(char **argv, char **env, int i)
{
	char	**cmd_path;
	char	**cmd;
	char	*path_exec;
	char	*path;

	if (argv[i][0] != '.' && argv[i][0] != '/' && argv[i][0] != '[' &&
		argv[i][0] != '_' && argv[i][0] != '~' && !((argv[i][0] >= 'a' && argv[i][0] <= 'z') ||
		(argv[i][0] >= 'A' && argv[i][0] <= 'Z')))
		return (NULL);
	cmd = ft_split(argv[i], ' ');
	if (!cmd || !cmd[0])
		return (NULL);
	if (access(cmd[0], X_OK | F_OK) == -1)
	{
		path = find_path(env);
		if (!path)
		{
			free_tab(cmd);
			return (NULL);
		}
		cmd_path = ft_split(path, ':');
		if (!cmd_path)
		{
			free_tab(cmd);
			return (NULL);
		}
		path_exec = exec_is_good(cmd_path, cmd, 0);
		if (!path_exec)
		{
			free_tab(cmd_path);
			free_tab(cmd);
			return (NULL);
		}
		free_tab(cmd_path);
		free_tab(cmd);
		return (path_exec);
	}
	path = strdup(cmd[0]);
	free_tab(cmd);
	return (path);
}

char	*exec_is_good(char **cmd_path, char **cmd, int i)
{
	char	*path_ex;
	char	*temp;

	while (cmd_path[i])
	{
		path_ex = ft_strjoin(cmd_path[i], "/");
		if (!path_ex)
			return (NULL);
		temp = ft_strjoin(path_ex, cmd[0]);
		free(path_ex);
		if (!temp)
			return (NULL);
		if (access(temp, X_OK | F_OK) == 0)
			return (temp);
		free(temp);
		i++;
	}
	return (NULL);
}

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
