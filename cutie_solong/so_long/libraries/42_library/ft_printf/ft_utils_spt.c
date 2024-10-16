/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_spt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:05 by klinn             #+#    #+#             */
/*   Updated: 2023/10/30 16:35:47 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_printer(t_arg *arg, char c)
{
	if (arg->minus)
	{
		ft_putchar_fd(c, arg->fd);
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
	}
	else
	{
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
		ft_putchar_fd(c, arg->fd);
	}
}

void	str_printer(t_arg *arg, char *str)
{
	if (arg->minus)
	{
		write(arg->fd, str, arg->precision);
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
	}
	else
	{
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
		write(arg->fd, str, arg->precision);
	}
}

void	ptr_printer(t_arg *arg, unsigned long long n)
{
	if (arg->minus && n != 0)
	{
		ft_putstr_fd("0x", arg->fd);
		ft_putunbr_base_fd(arg, n, 16);
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
	}
	else if (n == 0)
	{
		if (!arg->minus)
			while (arg->spad--)
				ft_putchar_fd(' ', arg->fd);
		ft_putstr_fd("(nil)", arg->fd);
		if (arg->minus)
			while (arg->spad--)
				ft_putchar_fd(' ', arg->fd);
	}
	else
	{
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
		ft_putstr_fd("0x", arg->fd);
		ft_putunbr_base_fd(arg, n, 16);
	}
}

void	int_printer(t_arg *arg, int n)
{
	if (arg->precision == 0 && n == 0 && arg->dot)
	{
		if (arg->width)
			arg->spad++;
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
	}
	else if (arg->minus)
	{
		ft_putsnbr_base_fd(arg, n, 10);
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
	}
	else
	{
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
		ft_putsnbr_base_fd(arg, n, 10);
	}
}

void	uint_printer(t_arg *arg, unsigned int n, int base)
{
	if (arg->precision == 0 && n == 0 && arg->dot)
	{
		if (arg->width)
			arg->spad++;
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
	}
	else if (arg->minus)
	{
		ft_putsnbr_base_fd(arg, n, base);
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
	}
	else
	{
		while (arg->spad--)
			ft_putchar_fd(' ', arg->fd);
		ft_putsnbr_base_fd(arg, n, base);
	}
}
