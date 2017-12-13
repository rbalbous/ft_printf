/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hhd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:31:29 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/12 23:15:54 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create(t_flags *flags, t_var *var, t_int8 d)
{
	if (d < 0)
		addchar('-', var);
	else if (flags->plus || flags->space)
		addchar(flags->plus ? '+' : ' ', var);
	d = (d > 0) ? -d : d;
	flags->precision = addmchar('0', var, flags->precision);
	pf_itoa_base(d, 10, flags, var);
}

static char	dinitialise(t_flags *flags, t_int8 d)
{
	int		test;
	int		flag;

	flags->len = pf_intlen(d, 10);
	test = (d < 0);
	flag = ((flags->space || flags->plus) && !test);
	flags->precision -= (flags->len - test);
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + flag;
	flags->fwidth *= (flags->fwidth > 0);
	flags->len -= 1 * (d < 0);
	return (' ');
}

int		pf_hhd(t_flags *flags, t_var *var, va_list *ap)
{
	char		width;
	t_int8		d;

	d = (t_int8)va_arg(*ap, int);
	if (d == 0 && flags->precision == 0)
		return (pf_empty(flags, var));
	width = dinitialise(flags, d);
	if (!flags->minus)
	{
		if (flags->zero && !flags->precision)
		{
			flags->precision = flags->fwidth;
			flags->fwidth = 0;
		}
		flags->fwidth = addmchar(width, var, flags->fwidth);
		create(flags, var, d);
	}
	else
	{
		create(flags, var, d);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}
