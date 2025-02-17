/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:01:11 by htopa             #+#    #+#             */
/*   Updated: 2024/10/31 14:45:11 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(void **arr, int is_int)
{
	int	j;

	j = -1;
	while (arr[++j] != NULL)
	{
		if (is_int == 1)
			free((int *)arr[j]);
		else
			free((char *)arr[j]);
	}
	free(arr);
}

int	open_and_check_file(char *filename, int type, int *fd)
{
	int	file;

	if (type == 0)
		file = open(filename, O_RDONLY, 0777);
	else
		file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
	{
		perror(filename);
		close(fd[0]);
		close(fd[1]);
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
			free_array((void **)paths, 0);
			return (command_path);
		}
		free(command_path);
		i++;
	}
	free_array((void **)paths, 0);
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
