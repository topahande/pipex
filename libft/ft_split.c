/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:15:38 by htopa             #+#    #+#             */
/*   Updated: 2024/05/13 13:19:09 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	does_exist(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	free_list(char **strs, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

static int	fill_array(char const *s, char c, char **arr)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
			while (s[i] == c && s[i] != '\0')
				i++;
		if (s[i] != c && s[i] != '\0')
		{
			index = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			arr[j] = ft_substr(s, index, i - index);
			if (arr[j] == NULL)
				return (free_list(arr, j));
			j++;
		}
		arr[j] = (void *)0;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**arr;

	if (s == NULL)
		return ((void *)0);
	count = get_word_count(s, c);
	arr = (char **)(malloc((count + 1) * sizeof(char *)));
	if (arr == NULL)
		return (NULL);
	if (count == 1 && does_exist(s, c) == 0)
	{
		arr[0] = ft_substr(s, 0, ft_strlen(s));
		if (arr[0] == NULL)
		{
			free_list(arr, 0);
			return (NULL);
		}
		arr[1] = (void *)0;
	}
	else if (count == 0)
		arr[count] = (void *)0;
	else if (fill_array(s, c, arr) == 0)
		return (NULL);
	return (arr);
}
