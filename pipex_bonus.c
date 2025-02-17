/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:33:50 by htopa             #+#    #+#             */
/*   Updated: 2024/12/13 09:25:14 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	command_not_found(int i, char **command_array, t_args *arg_struct)
{
	if (command_array[0] == NULL)
	{
		ft_putstr_fd(arg_struct->argv[i], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else
	{
		ft_putstr_fd(command_array[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	free_array_bonus((void **)command_array, 0, -1);
	free(arg_struct->pids);
	free(arg_struct);
	return (127);
}

static int	get_exit_code(void)
{
	if (errno == 13 || errno == 21)
		return (126);
	if (errno == 2)
		return (127);
	else
		return (errno);
}

static int	execute_command(char *path, char **command_array,
							t_args *arg_struct)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(21), 2);
		free(arg_struct->pids);
		free(arg_struct);
		free_array_bonus((void **)command_array, 0, -1);
		return (126);
	}
	else
	{
		execve(path, command_array, arg_struct->envp);
		perror(command_array[0]);
	}
	free(arg_struct->pids);
	free(arg_struct);
	free_array_bonus((void **)command_array, 0, -1);
	return (get_exit_code());
}

static int	run_pid(int i, t_args *arg_struct)
{
	char	*path;
	char	**command_array;
	int		check_status;

	command_array = ft_split(arg_struct->argv[i], ' ');
	path = find_command_path(command_array[0], arg_struct->envp);
	check_status = set_pipe(i, arg_struct, path);
	if (check_status == -1)
	{
		free_array_bonus((void **)command_array, 0, -1);
		free(path);
		exit(EXIT_FAILURE);
	}
	if (path != NULL)
		exit(execute_command(path, command_array, arg_struct));
	else
		exit(command_not_found(i, command_array, arg_struct));
}

int	main(int argc, char **argv, char **envp)
{
	int		wstatus;
	int		j;
	t_args	*arg_struct;

	arg_struct = prepare_struct(argc, argv, envp);
	if (arg_struct == NULL)
		exit(EXIT_FAILURE);
	j = -1;
	while (++j < argc - 3)
	{
		arg_struct->pids[j] = fork();
		if (arg_struct->pids[j] < 0)
			exit(display_error_message_bonus(2, arg_struct));
		if (arg_struct->pids[j] == 0)
			run_pid(j + 2, arg_struct);
	}
	close_and_free(arg_struct, 0);
	j = -1;
	while (++j < argc - 3)
		waitpid(arg_struct->pids[j], &wstatus, 0);
	free(arg_struct->pids);
	free(arg_struct);
	if (WIFEXITED(wstatus))
		exit(WEXITSTATUS(wstatus));
	exit(EXIT_FAILURE);
}
