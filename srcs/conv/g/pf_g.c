/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_g.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:42:14 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/17 19:55:12 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_gzero(t_flags *flags, t_var *var)
{
	char	width;

	width = ' ' + 16 * flags->zero;
	flags->fwidth -= 1 + (flags->plus || flags->space) + flags->hashtag;
	if ((flags->plus || flags->space) && flags->zero)
		addchar(flags->plus ? '+' : ' ', var);
	if (!flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	if ((flags->plus || flags->space) && !flags->zero)
		addchar(flags->plus ? '+' : ' ', var);
	addchar('0', var);
	if (flags->hashtag)
		addchar('.', var);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}

int		pf_ground(char *str, t_var *var)
{
	while (*str == '0')
	{
		var->bufindex--;
		str--;
	}
	if (*str == '.')
		var->bufindex--;
	return (0);
}

int		pf_gzer(t_flags *flags, t_var *var, long double d)
{
	long double	tmp;
	int		count;

	tmp = d;
	count = 0;
	while ((intmax_t)tmp == 0 && d != 0)
	{
		tmp *= 10;
		count++;
	}
	if (count > 4)
	{
		return (pf_ge(flags, var, tmp, -count));
	}
	else
	{
		return (pf_gf(flags, var, d));
	}
	return (0);
}

int		pf_gpos(t_flags *flags, t_var *var, long double d)
{
	int			count;

	count = 0;
	if (flags->len > flags->precision + 1)
	{
		flags->len = 1;
		count = pf_tosc(&d);
		pf_ge(flags, var, d, count);
	}
	else
		pf_gf(flags, var, d);
	return (1);
}

int		pf_g(t_flags *flags, t_var *var, va_list ap)
{
	long double	d;

	if (flags->bigl)
		d = va_arg(ap, long double);
	else
		d = va_arg(ap, double);
	flags->g = 1;
	if (d == 0 && flags->precision == 0)
		return (pf_gzero(flags, var));
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	/*flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
	flags->fwidth += (flags->precision == 0) * !flags->hashtag;
	flags->precision += (!flags->isp) * 7 - 1;
	flags->precision *= (flags->precision > 0);*/
	if ((intmax_t)d == 0) 
		pf_gzer(flags, var, d);
	else
		pf_gpos(flags, var, d);
	return (0);
}
