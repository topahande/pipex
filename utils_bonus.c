/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:01:11 by htopa             #+#    #+#             */
/*   Updated: 2024/10/31 19:02:23 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array_bonus(void **arr, int is_int, int j)
{
	if (j == -1)
	{
		while (arr[++j] != NULL)
		{
			if (is_int == 1)
				free((int *)arr[j]);
			else
				free((char *)arr[j]);
		}
	}
	else
	{
		while (--j >= 0)
		{
			if (is_int == 1)
				free((int *)arr[j]);
			else
				free((char *)arr[j]);
		}
	}
	free(arr);
}

int	close_and_free(t_args *arg_struct, int free_pid)
{
	close_pipes(arg_struct->fd, arg_struct->argc - 4);
	free_array_bonus((void **)arg_struct->fd, 1, arg_struct->argc - 4);
	if (free_pid == 1)
	{
		free(arg_struct->pids);
		free(arg_struct);
		return (-1);
	}
	else
		return (0);
}

int	open_and_check_file_bonus(char *filename, int type)
{
	int	file;

	if (type == 0)
		file = open(filename, O_RDONLY, 0777);
	else
		file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
	{
		perror(filename);
		return (-1);
	}
	return (file);
}

static char	*search_command_in_paths(char *cmd, char **paths)
{
	int		i;	
	char	*command_path;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		command_path = ft_strjoin(path, cmd);
		free(path);
		if (access(command_path, F_OK) == 0)
		{
			free_array_bonus((void **)paths, 0, -1);
			return (command_path);
		}
		free(command_path);
		i++;
	}
	free_array_bonus((void **)paths, 0, -1);
	return (0);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;

	if (cmd == NULL)
		return (NULL);
	if (envp == NULL || ft_strchr(cmd, 47) != 0)
		return (cmd);
	i = 0;
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (envp[i] == NULL)
		return (cmd);
	paths = ft_split(envp[i] + 5, ':');
	return (search_command_in_paths(cmd, paths));
}
