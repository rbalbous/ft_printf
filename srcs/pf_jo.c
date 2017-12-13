/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_jo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:17:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/13 19:37:31 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create(t_flags *flags, t_var *var, uintmax_t d)
{
	if (flags->hashtag)
		addchar('0', var);
	flags->precision = addmchar('0', var, flags->precision);
	pf_uitoa_base(d, 8, flags, var);
}

static char	initialise(t_flags *flags, uintmax_t d)
{
	flags->len = pf_uintlen(d, 8);
	flags->hashtag *= (d != 0 && !flags->precision);
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + flags->hashtag;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int		pf_jo(t_flags *flags, t_var *var, va_list *ap)
{
	char		width;
	uintmax_t	d;
	
	d = va_arg(*ap, uintmax_t);
	if (d == 0 && flags->precision == 0)
		return (pf_empty(flags, var));
	width = initialise(flags, d);
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