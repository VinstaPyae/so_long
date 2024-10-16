/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:34:59 by klinn             #+#    #+#             */
/*   Updated: 2023/10/04 17:35:03 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*arr;
	char	chr;

	arr = (char *)s;
	chr = (char)c;
	while (n--)
	{
		if (*arr == chr)
			return (arr);
		arr++;
	}
	return (0);
}
