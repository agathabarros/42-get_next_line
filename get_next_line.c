/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:22:30 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/08 12:46:28 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>


char *read_to_aux(int fd, char *str)
{
    char *buffer;
    int bytes;
    
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buffer)
        return(NULL);
    bytes = 1;
    while(!ft_strchr(str, '\n') && bytes != 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if(bytes == -1)
        {
            free(buffer);
            return(NULL);
        }
        buffer[bytes] = '\0';
        if(!buffer)
            return (NULL);
        str = ft_strjoin(str, buffer);
    }    
    free(buffer);
    return(str);
}


char *get_line(char *aux)
{
    int i;
    char *str;

    i = 0;
    if (!aux[i])
        return (NULL);
    while (aux[i] && aux [i] != '\n')
        i++;
    if (aux[i] == '\0')
        str = (char *)malloc(sizeof(char) * (i + 1));
    else 
        str = (char *)malloc(sizeof(char) * (i + 2));
    if (!str)
        return (NULL);
    i = 0;
    while (aux[i] && aux [i] != '\n')
    {
        str[i] = aux[i];
        i++;
    }
    if (aux[i] == '\n')
        str[i] = '\n';
    str[i] = '\n';
    return (str);
}

char *new_aux(char *aux)
{
    int i;
    int j;
    char *str;
    
    i = 0;
    j = 0;
    while(aux[i] && aux[i] != '\n')
        i++;
    if(!aux[i])
    {
        free(aux);
        return(NULL);
    }
    str = (char *)malloc(sizeof(char) * (ft_strlen(aux) - i + 1));
    if(!str)
        return(NULL);
    i++;
    while(aux[i])
        str[j] = aux [i];
        j++;
        i++;
    str[j] = '\0';
    free(aux);
    return(str);    
}
char *get_next_line(int fd)
{
    char    *line;
    static char *aux;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    aux = read_to_aux(fd, aux);
    if(!aux)
        return(NULL);
    line = get_line(aux);
    aux = new_aux(aux);
    return(line);    
}
