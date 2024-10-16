/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:26:29 by klinn             #+#    #+#             */
/*   Updated: 2023/10/30 16:32:45 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	int		word_len;
	t_arg	arg;

	ft_arg_init(&arg);
	arg.fd = 1;
	arg.len = 0;
	word_len = 0;
	va_start(arg.ap, string);
	while (*string)
	{
		if (*string == '%' && string++)
		{
			string = ft_main_process((char *)string, &arg);
			ft_arg_init(&arg);
		}
		else
		{
			word_len++;
			ft_putchar_fd(*string++, arg.fd);
		}
	}
	va_end(arg.ap);
	return (word_len + arg.len);
}

char	*ft_main_process(char *str, t_arg *arg)
{
	while (*str && !ft_strchr("cspdiuxX%", *str))
	{
		ft_flag_process(*str, arg);
		str++;
	}
	if (*str == 'c')
		ft_printf_char(arg);
	else if (*str == 's')
		ft_printf_str(arg);
	else if (*str == 'p')
		ft_printf_ptr(arg);
	else if (*str == 'd' || *str == 'i')
		ft_printf_int(arg);
	else if (*str == 'u')
		ft_printf_uint(arg, *str, 10);
	else if (*str == 'x' || *str == 'X')
		ft_printf_uint(arg, *str, 16);
	else if (*str == '%' && ++arg->len)
		ft_putchar_fd(*str, arg->fd);
	str++;
	arg->zp = 0;
	return (str);
}

void	ft_flag_process(char c, t_arg *arg)
{
	if (arg->dot)
		arg->zp = 1;
	if (ft_isdigit(c))
	{
		if (arg->dot || arg->zero)
			arg->precision = (arg->precision * 10 + c - '0');
		else
		{
			if (arg->width == 0 && c == '0')
				arg->zero = 1;
			else
				arg->width = (arg->width * 10 + c - '0');
		}
	}
	else if (c == '#')
		arg->hash = 1;
	else if (c == '-')
		arg->minus = 1;
	else if (c == ' ')
		arg->space = 1;
	else if (c == '+')
		arg->plus = 1;
	else if (c == '.')
		arg->dot = 1;
	wid_pre_changer(arg);
}

int	zz_zp_checker(t_arg *arg)
{
	return (arg->zz == 0 && arg->zp == 0);
}

void	wid_pre_changer(t_arg *arg)
{
	if (arg->dot && arg->precision && arg->zero && zz_zp_checker(arg))
	{
		arg->width = arg->precision;
		arg->precision = 0;
		arg->zz = 1;
	}
}
