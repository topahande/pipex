/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:01:06 by htopa             #+#    #+#             */
/*   Updated: 2024/11/14 21:02:51 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**envp;
	int		**fd;
	int		*pids;
}	t_args;

void	free_array(void **arr, int is_int);
void	free_array_bonus(void **arr, int is_int, int j);
int		open_and_check_file(char *filename, int type, int *fd);
int		open_and_check_file_bonus(char *filename, int type);
char	*find_command_path(char *cmd, char **envp);
int		check_arguments(int argc);
int		close_fd(int fd[2]);
void	close_pipes(int **fd, int j);
int		close_and_free(t_args *arg_struct, int free_pid);
int		set_pipe(int i, t_args *arg_struct, char *path);
t_args	*initialize_struct_with_pids_and_fd(int argc);
t_args	*add_fd_to_struct(t_args *arg_struct, int argc);
t_args	*prepare_struct(int argc, char **argv, char **envp);
int		display_error_message(int i, char	**command_array);
int		display_error_message_bonus(int i, t_args *arg_struct);
int		check_dup2(int file_d, t_args *arg_struct, int std_type);

#endif
