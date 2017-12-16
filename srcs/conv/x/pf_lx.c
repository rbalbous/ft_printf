/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:48:24 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/16 18:40:47 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create(t_flags *flags, t_var *var, unsigned long int d, unsigned char *str)
{
	char	x;

	x = 'x' - flags->capx * 32;
	if (flags->hashtag || str[var->index] == 'p')
	{
		addchar('0', var);
		addchar(x, var);
	}
	flags->precision = addmchar('0', var, flags->precision);
	pf_uitoa_hexa(d, flags, var);
}

static char	dinitialise(t_var *var, t_flags *flags, unsigned long int d, unsigned char *str)
{
	flags->len = pf_uintlen(d, 16);
	flags->hashtag = (str[var->index] == 'p');
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + flags->hashtag * 2;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int		pf_lx(t_flags *flags, t_var *var, va_list *ap, unsigned char *str)
{
	char		width;
	unsigned long int	d;

	d = va_arg(*ap, unsigned long int);
	if (d == 0 && flags->precision == 0 )
	{
		if (str[var->index] == 'p')
			addstr("0x", var);
		return (pf_empty(flags, var));
	}
	width = dinitialise(var, flags, d, str);
	if (!flags->minus)
	{
		if (flags->zero && !flags->precision)
		{
			flags->precision = flags->fwidth;
			flags->fwidth = 0;
		}
		flags->fwidth = addmchar(width, var, flags->fwidth);
		create(flags, var, d, str);
	}
	else
	{
		create(flags, var, d, str);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}
