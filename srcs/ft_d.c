/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:34 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/06 20:59:16 by rbalbous         ###   ########.fr       */
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
	if (flags->zero == 1)
	{
		if (flags->precision >= flags->fwidth)
			flags->isw = 0;
		else if (flags->isp == 0)
		{
			flags->precision = flags->fwidth;
			flags->isw = 0;
			flags->isp = 1;
		}
	}
	if (flags->isp && flags->precision >= len)
		if (d >= 0 || )
			flags->precision -= len;
		else
			flags->precision -= len -1;	
	else if (flags->isp)
		flags->isp = 0;
	if (flags->isw && flags->fwidth >= len)
		flags->fwidth -= len;
	else if (flags->isw)
		flags->isw = 0;
	if ((flags->space == 1 && d >= 0 && flags->isw == 0))
		addchar(' ', var);
	if (flags->minus > 0 && flags->isp)
	{
		if (flags->fwidth > flags->precision)
			flags->fwidth -= flags->precision;
		else
			flags->isw = 0;
		addwp(flags, var, 'p');
	}
	if (flags->minus == 0)
		wandp(flags, var);
	if (flags->plus == 1 && d >= 0)
	{
		if (var->buf[var->bufindex - flags->precision] == '0' ||
			var->buf[var->bufindex - flags->precision] == ' ')
		{
			var->buf[var->bufindex - flags->precision] = '+';
		}
		else
		{
			addchar('+', var);
			if (flags->minus == 1)
				flags->fwidth--;
		}
	}
	if (d < 0)
	{
		if (var->buf[var->bufindex - flags->precision] == '0' || 
			var->buf[var->bufindex - flags->precision] == ' ')
		{
			var->buf[var->bufindex - flags->precision] = '-';
			d = -d;
		}
		else
			flags->fwidth--;
	}
	addstr(ft_itoa(d), var);
	if (flags->minus != 0)
		addwp(flags, var, 'f');
	return (0);
}
