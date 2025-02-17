/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:41:49 by htopa             #+#    #+#             */
/*   Updated: 2024/04/27 14:31:28 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;
	size_t		i;

	cdst = (char *)dst;
	csrc = (const char *)src;
	if ((cdst - csrc) <= 0 || (size_t)(cdst - csrc) >= len)
		return (ft_memcpy(dst, src, len));
	else if ((size_t)(cdst - csrc) < len)
	{
		i = len;
		while (i > 0)
		{
			cdst[i - 1] = csrc[i - 1];
			i--;
		}
	}
	return (dst);
}
