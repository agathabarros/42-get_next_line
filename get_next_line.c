/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:22:30 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/27 23:14:50 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_keep(char *buffer) //get_keep returns the string after the first '\n' or '\0'
{
	int		i;
	int		j;
	int		size;
	char	*keep;

	i = ft_strlen_at(buffer, '\0'); //ft_strlen_at returns the length of the string until the first '\0' or '\n'
	j = ft_strlen_at(buffer, '\n'); 
	size = i - j + 1; 
	if (!buffer[j])
	{
		free (buffer);
		return (NULL);
	}
	keep = (char *)malloc(sizeof(char) * size);
	if (!keep)
	{
		return (NULL);
	}
	j++;
	ft_strncpy(keep, buffer + j, size);
	free (buffer);
	return (keep);
}

char	*get_line_gnl(char *buffer) 
{
	int		j;
	char	*line;

	j = ft_strlen_at(buffer, '\n');
	if (buffer[j] == '\n')
		j++;
	line = (char *)malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	ft_strncpy(line, buffer, j);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes;
	char		curr[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr[0] = '\0';
	bytes = 1;
	while (!newline(curr) && bytes != 0)
	{
		bytes = read(fd, curr, BUFFER_SIZE);
		if (bytes == -1 )
		{
			return (NULL);
		}
		curr[bytes] = '\0';
		buffer = ft_strjoin(buffer, curr);
	}
	line = get_line_gnl(buffer);
	buffer = get_keep(buffer);
	if (!line[0])
	{
		free (line);
		return (NULL);
	}
	return (line);
}
