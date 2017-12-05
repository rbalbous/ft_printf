/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:34 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/05 17:49:53 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int		ft_d(t_flags *flags, t_var *var, const char *str, va_list *ap)
{
	int	d;
	int len;

	d = va_arg(*ap, int);
	len = ft_intlen(d);
	(void)str;
	if (flags->zero != 0 && flags->fwidth && flags->fwidth && flags->precision == -1)
	{
		flags->precision = flags->fwidth;
		flags->fwidth = 0;
	}
	if (flags->precision != -1 && flags->precision > len)
		flags->precision -= len;
	else if (flags->precision != -1)
		flags->precision = -1;
	if (flags->fwidth && flags->fwidth > len)
		flags->fwidth -= len;
	else if (flags->fwidth)
		flags->fwidth = 0;
	if (flags->plus == 1 && d >= 0)
	{
		addchar('+', var);
		if (flags->fwidth)
			flags->fwidth--;
		if (flags->precision)
			flags->precision--;
	}
	if ((flags->space == 1 && d >= 0))
		addchar(' ', var);
	if (flags->minus > 0 && flags->precision > -1)
	{
		if (flags->fwidth > flags->precision)
			flags->fwidth -= flags->precision;
		else
			flags->fwidth = 0;
		addwp(flags, var, 'p');
	}
	if (d < 0 && flags->precision != -1)
	{
		addchar('-', var);
		d = -d;
		if (flags->zero != 1)
			flags->precision++;
	}
	if (flags->minus == 0)
		wandp(flags, var);
	if (d < 0 && flags->precision == -1)
	{
		addchar('-', var);
		d = -d;
	}
	addstr(ft_itoa(d), var);
	if (flags->minus != 0)
		addwp(flags, var, 'f');
	return (0);
}
