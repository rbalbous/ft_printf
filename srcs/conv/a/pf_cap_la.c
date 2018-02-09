/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_la.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:33:44 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/09 12:11:21 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	d = va_arg(ap, long double);
	width = initialise(flags, var, d);
	count = pf_tola(&d);
	if ((num = (pf_fltoa_hexa(d, flags))) == NULL)
		return (-1);
	pf_around(num + flags->len, flags, var);
	//ft_printf("%d %s\n", flags->len, num);
	flags->fwidth -= flags->len + 5 + (flags->space || flags->plus || d < 0);
	flags->fwidth *= (flags->fwidth > 0);
	if (!flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	if (d < 0)
		addchar('-', var);
	else if (flags->plus || flags->space)
		addchar(flags->plus * 11 + ' ', var);
	addstr("0X", var);
	addnstr(num, flags->len, var);
	if ((pf_create(var, flags, count)) == -1)
		return (-1);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}
