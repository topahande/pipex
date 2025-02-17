/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_messages.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:58:25 by htopa             #+#    #+#             */
/*   Updated: 2024/12/13 09:30:19 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	display_error_message(int i, char	**command_array)
{
	ft_putstr_fd("*************************\n", 2);
	if (i == 1)
		ft_putstr_fd("pipe() failed!\n", 2);
	else if (i == 2)
		ft_putstr_fd("fork() failed!\n", 2);
	else if (i == 3 && command_array != NULL)
	{
		ft_putstr_fd("dup2() failed!\n", 2);
		free_array((void **)command_array, 0);
	}
	ft_putstr_fd("*************************\n", 2);
	return (EXIT_FAILURE);
}

int	check_arguments(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("*************************************\n", 2);
		ft_putstr_fd("Error: Wrong number of arguments!\n\n", 2);
		ft_putstr_fd("Pipex takes only four arguments", 2);
		ft_putstr_fd(" in the following order:\n", 2);
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
		ft_putstr_fd("*************************************\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
