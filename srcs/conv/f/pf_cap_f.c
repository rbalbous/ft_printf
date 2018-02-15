/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:22:00 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/15 15:21:09 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_nanc(t_flags *flags, t_var *var)
{
	char	width;

	flags->fwidth -= 3;
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("NAN", 3, var);
	}
	else
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("NAN", 3, var);
	}
	return (0);
}

int		pf_infinitec(double d, t_flags *flags, t_var *var)
{
	char	width;

	flags->precision += 7 * (!flags->isp);
	flags->fwidth -= 3 + (flags->space || flags->plus || d < 0);
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("INF", 3, var);
	}
	else
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("INF", 3, var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}

int		pf_fcreate(t_flags *flags, t_var *var, double d, char width)
{
	if (!flags->minus)
	{
		if (d < 0 && flags->zero)
			addchar('-', var);
		else if ((flags->plus || flags->space) && flags->zero)
			addchar(flags->plus ? '+' : ' ', var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
		if (d < 0 && !flags->zero)
			addchar('-', var);
		else if ((flags->plus || flags->space) && !flags->zero)
			addchar(flags->plus ? '+' : ' ', var);
		pf_ftoa(d, flags, var);
		if (flags->precision == 0 && flags->hashtag)
			var->bufindex--;
		pf_round(&var->buf[var->bufindex - 1], flags, var);
	}
	else
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		pf_ftoa(d, flags, var);
		if (flags->precision == 0 && flags->hashtag)
			var->bufindex--;
		pf_round(&var->buf[var->bufindex - 1], flags, var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}

int		pf_cap_f(t_flags *flags, t_var *var, va_list ap)
{
	double		d;
	char		width;

	if (flags->bigl)
		return (pf_cap_fl(flags, var, ap));
	else
		d = va_arg(ap, double);
	flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
	flags->precision += 7 * (!flags->isp);
	width = ' ' + 16 * flags->zero;
	if (flags->precision == 0)
		return (pf_fzero(d, flags, var));
	if (d == 0 && flags->precision > 0)
	{
		flags->fwidth -= flags->precision + 2 + (flags->plus || flags->space);
		if ((flags->plus || flags->space) && flags->zero)
			addchar(flags->plus ? '+' : ' ', var);
		if (!flags->minus)
			flags->fwidth = addmchar(width, var, flags->fwidth);
		if ((flags->plus || flags->space) && !flags->zero)
			addchar(flags->plus ? '+' : ' ', var);
		addstr("0.", var);
		while (flags->precision-- > 0)
			addchar('0', var);
		if (flags->minus)
			flags->fwidth = addmchar(width, var, flags->fwidth);
		flags->precision += 7 * (!flags->isp);
		return (0);
	}
	return (pf_spe_cap_f(flags, var, d));
}

int		pf_spe_cap_f(t_flags *flags, t_var *var, double d)
{
	char		width;
	int			apo;

	if (!(d == d))
		return (pf_nanc(flags, var));
	if (d == INFINITY || d == -INFINITY || d == 9221120237041090560)
		return (pf_infinitec(d, flags, var));
	apo = (flags->tsep != 0) * ((flags->len / 3) - (flags->len % 3 == 0));
	flags->fwidth -= (flags->hashtag && flags->precision == 0);
	flags->fwidth *= (flags->fwidth > 0);
	flags->fwidth -= flags->precision * (!flags->g) + flags->len
	+ (flags->space || flags->plus || d < 0) + apo + (!flags->g);
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	pf_fcreate(flags, var, d, width);
	var->buf[var->bufindex] = 0;
	return (0);
}
