/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:26:35 by klinn             #+#    #+#             */
/*   Updated: 2023/10/30 16:34:12 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_init(t_arg *arg)
{
	arg->dot = 0;
	arg->hash = 0;
	arg->upper = 0;
	arg->minus = 0;
	arg->plus = 0;
	arg->space = 0;
	arg->zero = 0;
	arg->zz = 0;
	arg->zp = 0;
	arg->precision = 0;
	arg->width = 0;
	arg->spad = 0;
	arg->zpad = 0;
}

int	ft_allnblen(long long num, int base)
{
	if (num < 0)
	{
		num = -1 * num;
		return (1 + ft_allnblen(num, base));
	}
	if (!(num / base))
	{
		return (1);
	}
	return (1 + ft_allnblen(num / base, base));
}

int	ft_unsigned_allnblen(unsigned long long num, int base)
{
	if (!(num / base))
	{
		return (1);
	}
	return (1 + ft_unsigned_allnblen(num / base, base));
}

void	ft_putunbr_base_fd(t_arg *arg, unsigned long long num, int base)
{
	char	*digit;

	digit = "0123456789abcdef";
	if (num / base)
		ft_putunbr_base_fd(arg, num / base, base);
	ft_putchar_fd(digit[num % base], arg->fd);
}
