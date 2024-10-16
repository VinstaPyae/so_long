/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:26:26 by klinn             #+#    #+#             */
/*   Updated: 2023/10/30 15:13:08 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(t_arg *arg)
{
	char	c;

	c = va_arg(arg->ap, int);
	if (arg->width > arg->precision)
		arg->spad = arg->width - arg->precision - 1;
	arg->len += arg->spad + 1;
	char_printer(arg, c);
}

void	ft_printf_str(t_arg *arg)
{
	int		str_len;
	char	*str;

	str = va_arg(arg->ap, char *);
	if ((!str && arg->precision >= 6) || (!str && arg->precision == 0))
		str = "(null)";
	if (str == NULL && arg->precision < 6)
		str = "";
	str_len = ft_strlen(str);
	if (arg->dot == 0 || arg->precision > str_len)
		arg->precision = str_len;
	else if (arg->dot && arg->width > arg->precision)
		arg->precision = arg->precision;
	if (arg->width > arg->precision)
		arg->spad = arg->width - arg->precision;
	arg->len += arg->spad + arg->precision;
	str_printer(arg, str);
}

void	ft_printf_ptr(t_arg *arg)
{
	int			len;
	long long	n;

	n = va_arg(arg->ap, long long) + ULLONG_MAX + 1;
	if (n == 0)
		len = 5;
	else
		len = ft_unsigned_allnblen(n, 16) + 2;
	if (arg->width > len)
		arg->spad = arg->width - len;
	arg->len += arg->spad + len;
	ptr_printer(arg, n);
}

void	ft_printf_int(t_arg *arg)
{
	int	len;
	int	n;

	n = va_arg(arg->ap, int);
	len = ft_allnblen(n, 10);
	if (arg->precision && n < 0 && arg->dot)
		arg->precision++;
	if (arg->precision > len)
		arg->zpad = arg->precision - len;
	if (arg->width > arg->zpad + len)
		arg->spad = arg->width - arg->zpad - len;
	if ((arg->space || arg->plus) && n >= 0 && arg->spad)
	{
		arg->spad--;
		arg->len++;
	}
	arg->len += arg->spad + arg->zpad + len;
	int_printer(arg, n);
}

void	ft_printf_uint(t_arg *arg, char c, int base)
{
	unsigned int	n;
	int				len;

	n = va_arg(arg->ap, unsigned int);
	len = ft_unsigned_allnblen(n, base);
	if (c == 'X')
		arg->upper = 1;
	if (arg->hash && n > 0)
		arg->len += 2;
	if (arg->precision > len)
		arg->zpad = arg->precision - len;
	if (arg->width > len && !arg->precision)
		arg->spad = arg->width - len;
	if (arg->width > arg->precision && arg->dot && arg->width > len)
	{
		if (arg->precision < len)
			arg->spad = arg->width - len;
		else
			arg->spad = arg->width - arg->precision;
	}
	arg->len += arg->spad + arg->zpad + len;
	uint_printer(arg, n, base);
}
