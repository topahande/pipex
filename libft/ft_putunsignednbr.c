/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:42:12 by htopa             #+#    #+#             */
/*   Updated: 2024/10/14 12:48:37 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsignednbr(unsigned int n)
{
	int				i;
	int				write_check;

	write_check = ft_putunsignednbr_check(n);
	if (write_check == -1)
		return (-1);
	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
