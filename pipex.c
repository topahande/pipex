/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:00:46 by htopa             #+#    #+#             */
/*   Updated: 2024/12/13 09:15:01 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	command_not_found(char **command_array, char *arg)
{
	if (command_array[0] == NULL)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else
	{
		ft_putstr_fd(command_array[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	free_array((void **)command_array, 0);
	return (127);
}

static int	execute_command(char *path, char **command_array, char **envp)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(21), 2);
		free_array((void **)command_array, 0);
		return (126);
	}
	else
	{
		execve(path, command_array, envp);
		perror(command_array[0]);
	}
	free_array((void **)command_array, 0);
	if (errno == 13 || errno == 21)
		return (126);
	if (errno == 2)
		return (127);
	else
		return (errno);
}

static int	run_pid1(int *fd, char **argv, char **envp)
{
	int		filein;
	char	*path;
	char	**command_array_1;

	filein = open_and_check_file(argv[1], 0, fd);
	if (filein == -1)
		exit(EXIT_FAILURE);
	command_array_1 = ft_split(argv[2], ' ');
	if (dup2(filein, STDIN_FILENO) == -1)
		exit(display_error_message(3, command_array_1));
	close(fd[0]);
	close(filein);
	path = find_command_path(command_array_1[0], envp);
	if (path != NULL)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			exit(display_error_message(3, command_array_1));
		close(fd[1]);
		exit(execute_command(path, command_array_1, envp));
	}
	else
	{
		close(fd[1]);
		exit(command_not_found(command_array_1, argv[2]));
	}
}

static int	run_pid2(int *fd, char **argv, char **envp)
{
	int		fileout;
	char	*path;
	char	**command_array_2;

	fileout = open_and_check_file(argv[4], 1, fd);
	if (fileout == -1)
		exit(EXIT_FAILURE);
	command_array_2 = ft_split(argv[3], ' ');
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit(display_error_message(3, command_array_2));
	close(fd[1]);
	close(fd[0]);
	path = find_command_path(command_array_2[0], envp);
	if (path != NULL)
	{
		if (dup2(fileout, STDOUT_FILENO) == -1)
			exit(display_error_message(3, command_array_2));
		close(fileout);
		exit(execute_command(path, command_array_2, envp));
	}
	else
	{
		close(fileout);
		exit(command_not_found(command_array_2, argv[3]));
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		wstatus;

	check_arguments(argc);
	if (pipe(fd) == -1)
		exit(display_error_message(1, NULL));
	pid1 = fork();
	if (pid1 < 0)
		exit(display_error_message(2, NULL));
	if (pid1 == 0)
		run_pid1(fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		exit(display_error_message(2, NULL));
	if (pid2 == 0)
		run_pid2(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
		exit(WEXITSTATUS(wstatus));
	exit(EXIT_FAILURE);
}

// chmod u-rwx infile for permission denied
