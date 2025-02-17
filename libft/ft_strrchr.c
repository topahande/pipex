/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:32:24 by htopa             #+#    #+#             */
/*   Updated: 2024/04/22 14:51:04 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		p;
	char	char_c;

	char_c = (char)c;
	p = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == char_c)
			p = i;
		i++;
	}
	if (char_c == '\0')
		return ((char *)(s + i));
	if (p != -1)
		return ((char *)(s + p));
	else
		return (0);
}
