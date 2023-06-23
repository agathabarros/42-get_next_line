/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:44:57 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/23 09:37:28 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_at(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	newline(char *l)
{
	while (*l)
	{
		if (*l == '\n')
			return (1);
		l++;
	}
	return (0);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *prev, char *curr)
{
	int		i;
	int		j;
	int		size;
	char	*merge;

	i = ft_strlen_at(prev, '\0');
	j = ft_strlen_at(curr, '\0');
	size = i + j + 1;
	if (!prev && !curr)
		return (NULL);
	merge = (char *)malloc(sizeof(char) * size);
	if (!merge)
		return (NULL);
	if (prev)
		ft_strncpy(merge, prev, i);
	ft_strncpy(merge + i, curr, j);
	free (prev);
	return (merge);
}
