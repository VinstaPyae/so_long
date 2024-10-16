/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:26:32 by klinn             #+#    #+#             */
/*   Updated: 2023/12/23 12:47:18 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_arg
{
	int		fd;
	int		len;
	int		dot;
	int		space;
	int		zero;
	int		upper;
	int		hash;
	int		minus;
	int		plus;
	int		zz;
	int		zp;
	int		precision;
	int		width;
	int		zpad;
	int		spad;

	va_list	ap;
}			t_arg;
void		ft_reset(t_arg *arg);
void		ft_flag_process(char c, t_arg *arg);
void		wid_pre_changer(t_arg *arg);
void		ft_arg_init(t_arg *arg);
void		ft_printf_char(t_arg *arg);
void		ft_printf_str(t_arg *arg);
void		ft_printf_ptr(t_arg *arg);
void		ft_printf_int(t_arg *arg);
void		ft_printf_uint(t_arg *arg, char c, int base);
void		char_printer(t_arg *arg, char c);
void		str_printer(t_arg *arg, char *str);
void		ptr_printer(t_arg *arg, unsigned long long n);
void		int_printer(t_arg *arg, int n);
void		uint_printer(t_arg *arg, unsigned int n, int base);
void		ft_putsnbr_base_fd(t_arg *arg, long long num, int base);
void		ft_sub_putsnbr_base_fd(t_arg *arg, long long num);
void		ft_putunbr_base_fd(t_arg *arg, unsigned long long num, int base);
int			ft_printf(const char *string, ...);
int			zz_zp_checker(t_arg *arg);
int			ft_allnblen(long long num, int base);
int			ft_unsigned_allnblen(unsigned long long num, int base);
char		*ft_main_process(char *str, t_arg *arg);

#endif