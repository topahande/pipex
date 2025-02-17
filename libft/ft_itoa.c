/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:06:24 by htopa             #+#    #+#             */
/*   Updated: 2024/05/08 13:33:34 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

static long int	ft_make_positive(int n)
{
	long int	num;

	if (n < 0)
		num = -(long int)n;
	else
		num = (long int)n;
	return (num);
}

static int	ft_get_strlen(int n)
{
	int			len;
	long int	num;

	len = 1;
	num = ft_make_positive(n);
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	num;
	int			i;
	char		*s;

	num = ft_make_positive(n);
	len = ft_get_strlen(n);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (n < 0 && i == 0)
			s[i] = '-';
		else
		{
			s[i] = (num / ft_recursive_power(10, len - i - 1)) + '0';
			num = num % ft_recursive_power(10, len - i - 1);
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}
