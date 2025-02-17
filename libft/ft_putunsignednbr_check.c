/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:52:08 by htopa             #+#    #+#             */
/*   Updated: 2024/10/14 12:48:45 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsignednbr_check(unsigned int n)
{
	int	write_check;

	if (n > 9)
	{
		write_check = ft_putunsignednbr_check(n / 10);
		if (write_check == -1)
			return (-1);
	}
	write_check = ft_putchar(n % 10 + '0');
	if (write_check == -1)
		return (-1);
	return (1);
}
