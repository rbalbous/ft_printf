/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_la.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:07:23 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/15 16:24:47 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_azero(t_flags *flags, t_var *var, long double d)
{
	char	width;


	flags->fwidth -= 6 + (flags->space || flags->plus || d < 0)
	+ (flags->precision > 0 || flags->hashtag) + flags->precision * flags->isp;
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
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
	addchar('0', var);
	if (flags->precision > 0 || flags->hashtag)
		addchar('.', var);
	while (flags->precision-- > 0)
		addchar('0', var);
	addnstr("p+0", 3, var);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}

int			pf_tola(long double *d)
{
	int		count;

	count = -2 + (*d < 1 && *d > -1) * -2;
	*d *= 4 + (*d < 1 && *d > -1) * 12;
	while (16 < (*d) || -16 > (*d))
	{
		*d /= 2;
		count++;
	}
	while (8 > (*d) && -8 < (*d))
	{
		*d *= 2;
		count--;
	}
	return (count);
}

static int	initialise(t_flags *flags, t_var *var, long double d)
{
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->len = 1;
	flags->precision += 15 * (!flags->isp);
	return (' ' + 16 * flags->zero);
}

int			pf_la(t_flags *flags, t_var *var, va_list ap)
{
	long double	d;
	int			count;
	char		width;
	char		*num;
	int			len_count;

	d = va_arg(ap, long double);
	if (d == 0)
		return (pf_azero(flags, var, d));
	//ft_printf("%.20Lf\n", d);
	//printf("%.20Lf\n", d);
	width = initialise(flags, var, d);
	count = pf_tola(&d);
	len_count = pf_intlen(count, 10) - (count < 0);
	if ((num = (pf_ftoa_hexa(d, flags))) == NULL)
		return (-1);
	//ft_printf("%s %c %c %d\n", num, num[flags->len], num[flags->len - 1], flags->len);
	pf_around(num + flags->len, "0123456789abcdef", flags, d);
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
