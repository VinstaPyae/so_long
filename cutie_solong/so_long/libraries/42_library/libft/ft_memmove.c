/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:35:58 by klinn             #+#    #+#             */
/*   Updated: 2023/10/04 17:36:00 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		dptr = (unsigned char *)dest;
		sptr = (unsigned char *)src;
		while (n--)
			*dptr++ = *sptr++;
	}
	else
	{
		dptr = (unsigned char *)dest + (n - 1);
		sptr = (unsigned char *)src + (n - 1);
		while (n--)
			*dptr-- = *sptr--;
	}
	return (dest);
}
