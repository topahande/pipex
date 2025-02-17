/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:41:32 by htopa             #+#    #+#             */
/*   Updated: 2024/10/14 12:49:04 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer(void *p)
{
	int	write_check;

	write_check = write(1, "0x", 2);
	if (write_check == -1)
		return (-1);
	write_check = ft_puthexadecimal((unsigned long int)p, 'x');
	if (write_check == -1)
		return (-1);
	return (write_check + 2);
}
