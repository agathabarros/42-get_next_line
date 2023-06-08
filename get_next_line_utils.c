/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:44:57 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/08 12:08:25 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin(char *s1,  char *s2)
{
    char	*join;
	int		i;
	int		j;

	
    if(!s1)
    {
        s1 = malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    i = ft_strlen(s1);
	j = 0;
    join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (join == NULL )
		return (0);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
    free(s1);
	join[i + j] = '\0';
	return (join);
}

char    *ft_strchr(char *buffer, int c)
{
    int i;

    i = 0;
    if(!buffer)
        return (NULL);
    while (buffer[i])
    {
        if ((unsigned char)buffer[i] == (unsigned char)c)
            return (&buffer[i]);
        i++;
    }
    if ((unsigned char)buffer[i] == (unsigned char)c)
            return (&buffer[i]);
    return (NULL);
}

size_t  ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    if(!str)
        return (0);
    while(str[i] && str[i] != '\n')
    {
        i++;
    }
    if(str[i] == '\0')
        i++;
    return(i);
}
