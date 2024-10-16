/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:24:37 by klinn             #+#    #+#             */
/*   Updated: 2023/12/01 17:56:32 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

char	*ft_gnl_strjoin(char *str1, char *str2);
char	*ft_gnl_strdup(char *s);
char	*get_next_line(int fd);
char	*add_data(int fd, char *saved);
char	*ft_get_line(char *saved);
char	*renew_line(char *saved);
int		ft_gnl_strlen(char *str);
int		ft_gnl_strchr(const char *str);
void	ft_free(char *c);

#endif
