/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:41:52 by htopa             #+#    #+#             */
/*   Updated: 2024/10/14 12:48:54 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;
	int	write_check;

	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		write_check = ft_putchar(s[i]);
		if (write_check == -1)
			return (-1);
		i++;
	}
	return (i);
}
