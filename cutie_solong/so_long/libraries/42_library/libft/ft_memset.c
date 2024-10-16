/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:36:10 by klinn             #+#    #+#             */
/*   Updated: 2023/10/04 17:36:12 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	if (len == 0)
	{
		return (b);
	}
	ptr = (unsigned char *)b;
	while (len--)
	{
		*ptr = (unsigned char)c;
		if (len)
			ptr++;
	}
	return (b);
}
