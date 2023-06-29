/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:44:57 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/27 23:22:55 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen( char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		a;
	char	*str;

	i = ft_strlen(str1);
	a = ft_strlen(str2);
	str = malloc(sizeof(char) * ((i + a) + 1));
	if (!str)
		return (0);
	i = 0;
	a = 0;
	while (str1[i])
		str[a++] = str1[i++];
	i = 0;
	while (str2[i])
		str[a++] = str2[i++];
	str[a] = '\0';
	free(str1);
	return (str);
}
void	*ft_calloc(size_t nitems, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(nitems * size);
	if (memory == NULL)
		return (0);
	while (i < nitems * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
