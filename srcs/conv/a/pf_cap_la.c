/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_la.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:33:44 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/15 13:12:33 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		pf_cap_azero(t_flags *flags, t_var *var, long double d)
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
		addstr("0X", var);
	}
	if (!flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	if (!flags->zero)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus * 11 + ' ', var);
		addstr("0X", var);
	}
	addchar('0', var);
	if (flags->precision > 0 || flags->hashtag)
		addchar('.', var);
	while (flags->precision-- > 0)
		addchar('0', var);
	addnstr("P+0", 3, var);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}

static int	pf_create(t_var *var, t_flags *flags, int count)
{
	int		start;

	start = var->bufindex - 2 - flags->len;
	addchar('P', var);
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

static int	initialise(t_flags *flags, t_var *var, long double d)
{
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->len = 1;
	flags->precision += 15 * (!flags->isp) - 1;
	return (' ' + 16 * flags->zero);
	return (0);
}

int			pf_cap_la(t_flags *flags, t_var *var, va_list ap)
{	
	long double	d;
	int			count;
	char		width;
	char		*num;
	int			len_count;

	d = va_arg(ap, long double);
	if (d == 0)
		return (pf_cap_azero(flags, var, d));
	flags->capx = 1;
	width = initialise(flags, var, d);
	count = pf_tola(&d);
	if ((num = (pf_fltoa_hexa(d, flags))) == NULL)
		return (-1);
	pf_around(num + flags->len - 1, "0123456789abcdef", flags, d);
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
		addstr("0X", var);
	}
	if (!flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	if (!flags->zero)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus * 11 + ' ', var);
		addstr("0X", var);
	}
	addnstr(num, flags->len, var);
	if ((pf_create(var, flags, count)) == -1)
		return (-1);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	free(num);
	return (0);
}
