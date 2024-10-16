/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:48:26 by klinn             #+#    #+#             */
/*   Updated: 2023/10/04 18:48:28 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
	size_t	src_len;
	size_t	count;

	count = 0;
	src_len = ft_strlen(src);
	if (maxlen == 0)
		return (src_len);
	while (src[count] != '\0' && count < (maxlen - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (src_len);
}
