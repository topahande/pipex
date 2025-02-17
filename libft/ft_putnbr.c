/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:41:14 by htopa             #+#    #+#             */
/*   Updated: 2024/10/14 12:50:32 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int c)
{
	int	i;
	int	write_check;

	i = 1;
	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	if (c < 0)
	{
		write_check = ft_putchar('-');
		if (write_check == -1)
			return (-1);
		c = -c;
		i++;
	}
	write_check = ft_putnbr_positive(c);
	if (write_check == -1)
		return (-1);
	while (c > 9)
	{
		c = c / 10;
		i++;
	}
	return (i);
}
