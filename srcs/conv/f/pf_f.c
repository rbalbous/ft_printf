/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:30:50 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/20 22:03:59 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		pf_infinite(double d, t_flags *flags, t_var *var)
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
		flags->fwidth = addmchar(width, var, flags->fwidth);
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("inf", 3, var);
	}
	return (0);
}

static int		pf_nan(t_flags *flags, t_var *var)
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

int				pf_fcreate(t_flags *flags, t_var *var, double d, char width)
{
	if (!flags->minus)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
		pf_ftoa(d, flags, var);
		pf_round(&var->buf[var->bufindex - 1], flags, var);
	}
	else
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		pf_ftoa(d, flags, var);
		pf_round(&var->buf[var->bufindex - 1], flags, var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	
	return (0);
}

int				pf_round(char *str, t_flags *flags, t_var *var)
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
	return (0);
}

int				pf_f(t_flags *flags, t_var *var, va_list *ap)
{
	double		d;
	int			start;
	char		width;

	start = var->bufindex;
	d = va_arg(*ap, double);
	if (d == 9221120237041090560)
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY || d == 9221120237041090560)
		return (pf_infinite(d, flags, var));
	flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
	flags->fwidth -= (flags->hashtag && flags->precision == 0);
	flags->precision += 7 * (!flags->isp);
	flags->fwidth -= flags->precision + flags->len + (flags->precision != 0)
	+ (flags->space || flags->plus);
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	pf_fcreate(flags, var, d, width);
	var->buf[var->bufindex] = 0;
	return (0);
}
