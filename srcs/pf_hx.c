/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:12:49 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/12 21:57:59 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create(t_flags *flags, t_var *var, short int d)
{
	char	x;

	x = 'x' - flags->capx * 32;
	if (flags->hashtag)
	{
		addchar('0', var);
		addchar(x, var);
	}
	flags->precision = addmchar('0', var, flags->precision);
	pf_uitoa_hexa(d, 16, flags, var);
}

static char	dinitialise(t_flags *flags, short int d)
{
	flags->len = pf_uintlen(d, 16);
	flags->hashtag *= (d != 0);
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + flags->hashtag * 2;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int		pf_hx(t_flags *flags, t_var *var, va_list *ap)
{
	char		width;
	short int	d;

	d = (short int)va_arg(*ap, int);
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
