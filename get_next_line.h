/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:22:25 by agpereir          #+#    #+#             */
/*   Updated: 2023/06/27 22:51:24 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//get_next_line
char	*get_keep(char *buffer);
char	*get_line_gnl(char *buffer);
char	*get_next_line(int fd);
//get_next_line_utils
int	ft_strlen( char *str);
char	*ft_strjoin(char *s1, char *s2);
int	    ft_strchr(char *str, char c);
#endif