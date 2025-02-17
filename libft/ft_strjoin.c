/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:18:47 by htopa             #+#    #+#             */
/*   Updated: 2024/09/13 13:12:55 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*s3;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (s3 == NULL || (s1 == NULL && s2 == NULL))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		s3[len_s1 + i] = s2[i];
		i++;
	}
	s3[len_s1 + i] = '\0';
	return (s3);
}

/*#include "../pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*s3;
	size_t	len_s1;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) * (len_s1 + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i] != '\0')
		s3[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		s3[len_s1 + i] = s2[i];
	s3[len_s1 + i] = '\0';
	ft_free(&s1);
	return (s3);
}
*/
