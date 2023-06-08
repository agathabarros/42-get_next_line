/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:22:25 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/08 11:56:30 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char *get_next_line(int fd);

//get_next_line_

char *read_to_aux(int fd, char *str);
char *new_aux(char *aux);
char *get_line(char *aux);

//get_next_line_utils
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(char *buffer, int c);
size_t  ft_strlen(const char *str);

#endif