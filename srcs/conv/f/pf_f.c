/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:30:50 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/15 15:22:13 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_fzero(double d, t_flags *flags, t_var *var)
{
	char	width;

	flags->fwidth -= (flags->hashtag);
	flags->fwidth *= (flags->fwidth > 0);
	flags->fwidth -= (flags->space || flags->plus || (d < 0));
	flags->fwidth *= (flags->fwidth > 0);
	flags->fwidth -= flags->len;
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	pf_fcreate(flags, var, d, width);
	var->buf[var->bufindex] = 0;
	return (0);
}

int		pf_infinite(double d, t_flags *flags, t_var *var)
{
	int		width;

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
		addnstr("inf", 3, var);
	}
	else
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("inf", 3, var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}

int		pf_nan(t_flags *flags, t_var *var)
{
	char	width;

	flags->fwidth -= 3;
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("nan", 3, var);
	}
	else
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("nan", 3, var);
	}
	return (0);
}

int		pf_round(char *str, t_flags *flags, t_var *var)
{
	if (*str >= '5')
	{
		while (*(--str) == '9')
			*str = '0';
		if (*str == '.')
		{
			if (*(str + 2) == 0 && !flags->hashtag)
			{
				*str = 0;
				var->bufindex--;
			}
			*(--str) += 1;
		}
		else
			*str += 1;
	}
	else if (*(--str) == '.' && !flags->hashtag)
	{
		*str = 0;
		var->bufindex--;
	}
	var->bufindex--;
	if (flags->g && !flags->hashtag)
		return (pf_ground(&var->buf[var->bufindex - 1], var));
	return (0);
}

int		pf_f(t_flags *flags, t_var *var, va_list ap)
{
	double		d;
	char		width;
	int			apo;

	if (flags->bigl)
		return (pf_fl(flags, var, ap));
	else
		d = va_arg(ap, double);
	flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
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
		return (0);
	}
	flags->precision += 7 * (!flags->isp);
	apo = (flags->tsep != 0) * ((flags->len / 3) - (flags->len % 3 == 0));
	flags->fwidth -= flags->precision + flags->len
	+ (flags->space || flags->plus || d < 0) + apo + 1;
	flags->fwidth *= (flags->fwidth > 0);
	return (pf_spe_f(flags, var, d));
}

int		pf_spe_f(t_flags *flags, t_var *var, double d)
{
	char		width;

	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	width = ' ' + 16 * flags->zero;
	pf_fcreate(flags, var, d, width);
	var->buf[var->bufindex] = 0;
	return (0);
}
