/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:52:18 by htopa             #+#    #+#             */
/*   Updated: 2024/09/13 13:08:37 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s || len == 0)
		return (0);
	if (len > len_s - start)
		len = len_s - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL || s == NULL)
		return (NULL);
	i = start;
	while (s[i] != '\0' && i < start + len)
	{
		substr[i - start] = s[i];
		i++;
	}
	substr[i - start] = '\0';
	return (substr);
}
