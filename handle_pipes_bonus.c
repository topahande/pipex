/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:43:07 by htopa             #+#    #+#             */
/*   Updated: 2024/12/13 09:29:49 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(int **fd, int j)
{
	int	i;

	i = -1;
	while (++i < j)
	{
		if (fd[i] != NULL)
		{
			close(fd[i][0]);
			close(fd[i][1]);
		}
	}
}

t_args	*add_fd_to_struct(t_args *arg_struct, int argc)
{
	int		j;

	arg_struct->fd = malloc(sizeof(int *) * (argc - 4));
	if (arg_struct->fd == NULL)
	{
		free(arg_struct->pids);
		free(arg_struct);
		return (NULL);
	}
	j = -1;
	while (++j < argc - 4)
	{
		arg_struct->fd[j] = malloc(2 * sizeof(int));
		if (arg_struct->fd[j] == NULL)
		{
			close_pipes(arg_struct->fd, j);
			free_array_bonus((void **)arg_struct->fd, 1, j);
			free(arg_struct->pids);
			free(arg_struct);
			return (NULL);
		}
	}
	return (arg_struct);
}

t_args	*initialize_struct_with_pids_and_fd(int argc)
{
	t_args	*arg_struct;

	arg_struct = malloc(sizeof(t_args));
	if (arg_struct == NULL)
		return (NULL);
	arg_struct->pids = malloc(sizeof(pid_t) * (argc - 3));
	if (arg_struct->pids == NULL)
	{
		free(arg_struct);
		return (NULL);
	}
	return (add_fd_to_struct(arg_struct, argc));
}

t_args	*prepare_struct(int argc, char **argv, char **envp)
{
	int		j;
	t_args	*arg_struct;

	arg_struct = initialize_struct_with_pids_and_fd(argc);
	if (arg_struct == NULL)
	{
		display_error_message_bonus(4, arg_struct);
		return (NULL);
	}
	arg_struct->argc = argc;
	arg_struct->argv = argv;
	arg_struct->envp = envp;
	j = -1;
	while (++j < argc - 4)
	{
		if (pipe(arg_struct->fd[j]) == -1)
		{
			close_pipes(arg_struct->fd, j);
			free_array_bonus((void **)arg_struct->fd, 1, argc - 4);
			display_error_message_bonus(1, arg_struct);
			return (NULL);
		}
	}
	return (arg_struct);
}

int	set_pipe(int i, t_args *arg_struct, char *path)
{
	int	file_d;

	if (i == 2)
	{
		file_d = open_and_check_file_bonus(arg_struct->argv[i - 1], 0);
		if (check_dup2(file_d, arg_struct, STDIN_FILENO) == -1)
			return (-1);
		close(file_d);
	}
	else if (dup2(arg_struct->fd[i - 3][0], STDIN_FILENO) == -1)
		return (display_error_message_bonus(3, arg_struct));
	if (i == arg_struct->argc - 2)
	{
		file_d = open_and_check_file_bonus(
				arg_struct->argv[arg_struct->argc - 1], 1);
		if (file_d == -1)
			return (close_and_free(arg_struct, 1));
		if (path != NULL && dup2(file_d, STDOUT_FILENO) == -1)
			return (display_error_message_bonus(3, arg_struct));
		close(file_d);
	}
	else if (path != NULL
		&& dup2(arg_struct->fd[i - 2][1], STDOUT_FILENO) == -1)
		return (display_error_message_bonus(3, arg_struct));
	return (close_and_free(arg_struct, 0));
}
