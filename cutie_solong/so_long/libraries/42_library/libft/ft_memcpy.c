/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:35:42 by klinn             #+#    #+#             */
/*   Updated: 2023/10/04 17:35:44 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	size_t			i;

	if (!dest && !src)
		return (0);
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*dptr++ = *sptr++;
	return (dest);
}
