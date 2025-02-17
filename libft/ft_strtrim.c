/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:40:04 by htopa             #+#    #+#             */
/*   Updated: 2024/05/03 16:41:42 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start_index(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		found = 0;
		while (set[j] != '\0')
		{
			if (s1[i] != set[j])
				j++;
			else
			{
				i++;
				found = 1;
			}
		}
		if (set[j] == '\0' && found == 0)
			return (i);
	}
	return (-1);
}

static int	get_end_index(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		found = 0;
		while (set[j] != '\0')
		{
			if (s1[i] != set[j])
				j++;
			else
			{
				i--;
				found = 1;
			}
		}
		if (set[j] == '\0' && found == 0)
			return (i);
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = get_start_index(s1, set);
	end = get_end_index(s1, set);
	if (start == -1 && end == -1)
		return (ft_strdup("\0"));
	else
		return (ft_substr(s1, start, end - start + 1));
}
