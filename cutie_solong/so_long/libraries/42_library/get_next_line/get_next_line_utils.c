/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:21:39 by klinn             #+#    #+#             */
/*   Updated: 2023/12/01 17:48:23 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strdup(char *s)
{
	char	*rtn;
	int		i;

	i = 0;
	rtn = malloc(sizeof(char) * (ft_gnl_strlen(s) + BUFFER_SIZE));
	if (!rtn)
	{
		ft_free(rtn);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		rtn[i] = s[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	ft_gnl_strchr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*rtn;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	rtn = malloc(sizeof(char) * (ft_gnl_strlen(str1) + ft_gnl_strlen(str2)
				+ 1));
	if (rtn == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str1)
		while (str1[++i] != '\0')
			rtn[i] = str1[i];
	while (str2[j] != '\0')
		rtn[i++] = str2[j++];
	rtn[ft_gnl_strlen(str1) + ft_gnl_strlen(str2)] = '\0';
	ft_free(str1);
	return (rtn);
}
