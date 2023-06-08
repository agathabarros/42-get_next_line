/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:45:09 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/08 11:55:47 by agpereir         ###   ########.fr       */
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
    line = (char *) -1;
    while(line != NULL)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
    }
    close(fd);
}