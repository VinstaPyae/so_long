/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:21:31 by klinn             #+#    #+#             */
/*   Updated: 2023/12/01 17:49:19 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*renew_line(char *saved)
{
	char	*rtn;
	int		i;

	if (!saved)
		return (NULL);
	i = ft_gnl_strchr(saved) + 1;
	if (i == 0 || saved[i] == '\0')
	{
		ft_free(saved);
		return (NULL);
	}
	rtn = ft_gnl_strdup((saved + i));
	if (!rtn)
		return (NULL);
	ft_free(saved);
	return (rtn);
}

char	*ft_get_line(char *saved)
{
	int		len;
	int		i;
	char	*rtn;

	i = -1;
	if (!saved || saved[0] == '\0')
		return (NULL);
	len = ft_gnl_strchr(saved) + 1;
	if (len == 0)
		len = ft_gnl_strlen(saved);
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	while (++i < len)
		rtn[i] = saved[i];
	rtn[i] = '\0';
	return (rtn);
}

char	*add_data(int fd, char *saved)
{
	int		byte_read;
	char	*buf;

	buf = (char *)malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		ft_free(buf);
		return (NULL);
	}
	byte_read = 1;
	while (byte_read != 0 && ft_gnl_strchr(saved) == -1)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			ft_free(saved);
			ft_free(buf);
			return (NULL);
		}
		buf[byte_read] = '\0';
		saved = ft_gnl_strjoin(saved, buf);
	}
	free(buf);
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*saved = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		ft_free(saved);
		return (NULL);
	}
	saved = add_data(fd, saved);
	if (!saved)
	{
		ft_free(saved);
		return (NULL);
	}
	next_line = ft_get_line(saved);
	saved = renew_line(saved);
	return (next_line);
}

void	ft_free(char *c)
{
	free(c);
	c = NULL;
}
