/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:07:23 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/09 18:32:50 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_around(char *str, t_flags *flags, t_var *var)
{
	(void)var;
	if (*str >= '8')
	{
		while (*(--str) == 'f')
		{
			*str = '0';
			flags->len--;
		}
		if (*str == '.')
		{
			*str += 1 + 40 * (*str == '9');;
		}
		else
			*str += 1 + 40 * (*str == '9');
	}
	else if (*(--str) == '.' && !flags->hashtag)
	{
		*str = 0;
		flags->len--;
	}
	return (0);
}

int			pf_toa(double *d)
{
	int		count;
	int		sign;

	count = 0;
	sign = 1;
	if ((intmax_t)(*d) == 0 && *d != 0)
	{
		while ((intmax_t)(*d) == 0)
		{
			*d = *d * 2;
			count++;
			sign = -1;
		}
	}
	while ((1 < (intmax_t)(*d) || -1 > (intmax_t)(*d)) && *d != 0)
	{
		*d /= 2;
		count++;
	}
	return (count * sign);
}

int			pf_acreate(t_var *var, t_flags *flags, int count)
{
	int		start;

	start = var->bufindex - 2 - flags->len;
	addchar('p', var);
	if (count < 0)
	{
		addchar('-', var);
		count *= -1;
	}
	else
		addchar('+', var);
	addstr(ft_itoa(count), var);
	return (0);
}

static char	initialise(t_flags *flags, t_var *var, double d)
{
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->len = 1;
	flags->precision += 15 * (!flags->isp) - 1;
	return (' ' + 16 * flags->zero);
}

int			pf_a(t_flags *flags, t_var *var, va_list ap)
{
	double		d;
	int			count;
	char		width;
	char		*num;
	int			len_count;

	if (flags->bigl)
		return (pf_la(flags, var, ap));
	d = va_arg(ap, double);
	width = initialise(flags, var, d);
	count = pf_toa(&d);
	if ((num = (pf_ftoa_hexa(d, flags))) == NULL)
		return (-1);
	pf_around(num + flags->len, flags, var);
	len_count = pf_intlen(count, 10) - (count < 0);
	flags->fwidth -= flags->len + 4 + len_count + (flags->space || flags->plus || d < 0) 
	+ (flags->precision == -1 && flags->hashtag);
	flags->fwidth *= (flags->fwidth > 0);
	if (flags->precision == -1 && flags->hashtag)
		flags->len++;
	if (flags->zero)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus * 11 + ' ', var);
		addstr("0x", var);
	}
	if (!flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	if (!flags->zero)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus * 11 + ' ', var);
		addstr("0x", var);
	}
	addnstr(num, flags->len, var);
	if ((pf_acreate(var, flags, count)) == -1)
		return (-1);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	free(num);
	return (0);
}
