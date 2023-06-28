/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:45:09 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/27 22:58:14 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>



int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
}

/*int main(void)
{
    int fd;
    char *line;
   
    fd = open("text.txt", O_RDONLY);
    line = (char *) - 1;
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    close(fd);
}*/
