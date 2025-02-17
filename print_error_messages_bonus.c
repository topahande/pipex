/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_messages_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:58:25 by htopa             #+#    #+#             */
/*   Updated: 2024/12/13 09:23:33 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	display_error_message_bonus(int i, t_args *arg_struct)
{
	ft_putstr_fd("*************************\n", 2);
	if (i == 1)
	{
		ft_putstr_fd("pipe() failed!\n", 2);
		free(arg_struct->pids);
		free(arg_struct);
	}
	else if (i == 2)
	{
		ft_putstr_fd("fork() failed!\n", 2);
		return (close_and_free(arg_struct, 1));
	}
	else if (i == 3)
	{
		ft_putstr_fd("dup2() failed!\n", 2);
		return (close_and_free(arg_struct, 1));
	}
	else if (i == 4)
		ft_putstr_fd("mallloc() failed!\n", 2);
	ft_putstr_fd("*************************\n", 2);
	return (EXIT_FAILURE);
}

int	check_dup2(int file_d, t_args *arg_struct, int std_type)
{
	if (file_d == -1)
		return (close_and_free(arg_struct, 1));
	if (dup2(file_d, std_type) == -1)
		return (display_error_message_bonus(3, arg_struct));
	return (0);
}
