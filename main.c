/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:45:09 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/27 19:53:03 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>



int main(void)
{
    int fd;
    char *line;
   
    fd = open("text.txt", O_RDONLY);
    line = (char *) - 1;
    while(line != NULL)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
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
