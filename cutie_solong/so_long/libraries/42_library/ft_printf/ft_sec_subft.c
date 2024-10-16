/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sec_subft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:17:29 by klinn             #+#    #+#             */
/*   Updated: 2024/03/21 14:54:05 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset(t_arg *arg)
{
	arg->hash = 0;
	arg->plus = 0;
	arg->space = 0;
}

void	ft_putsnbr_base_fd(t_arg *arg, long long num, int base)
{
	const char	*digit;

	digit = "0123456789abcdef";
	if (arg->upper == 1)
		digit = "0123456789ABCDEF";
	ft_sub_putsnbr_base_fd(arg, num);
	if (num < 0)
	{
		num = -1 * num;
	}
	if (num / base)
		ft_putsnbr_base_fd(arg, num / base, base);
	ft_putchar_fd(digit[num % base], arg->fd);
}

void	ft_sub_putsnbr_base_fd(t_arg *arg, long long num)
{
	if (num < 0)
	{
		num = -1 * num;
		ft_putchar_fd('-', arg->fd);
	}
	else if (arg->hash && arg->upper && num != 0)
		ft_putstr_fd("0X", arg->fd);
	else if (arg->hash && !arg->upper && num != 0)
		ft_putstr_fd("0x", arg->fd);
	else if (arg->plus)
	{
		ft_putchar_fd('+', arg->fd);
		arg->len++;
	}
	else if (arg->space)
	{
		ft_putchar_fd(' ', arg->fd);
		arg->len++;
	}
	while (arg->zpad > 0)
	{
		ft_putchar_fd('0', arg->fd);
		arg->zpad--;
	}
	ft_reset(arg);
}
