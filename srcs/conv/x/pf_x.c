/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:53 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/30 13:35:58 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_len_x(int (*len_x[7])())
{
	len_x[0] = pf_sp_x;
	len_x[1] = pf_hhx;
	len_x[2] = pf_hx;
	len_x[3] = pf_lx;
	len_x[4] = pf_llx;
	len_x[5] = pf_jx;
	len_x[6] = pf_zx;
}

static void	create(t_flags *flags, t_var *var, t_uint32 d)
{
	char	x;

	x = 'x' - flags->capx * 32;
	if (flags->hashtag)
	{
		addchar('0', var);
		addchar(x, var);
	}
	flags->precision = addmchar('0', var, flags->precision);
	pf_uitoa_hexa(d, flags, var);
}

static char	dinitialise(t_flags *flags, t_uint32 d)
{
	flags->len = pf_uintlen(d, 16);
	flags->hashtag *= (d != 0);
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + flags->hashtag * 2;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int			pf_x(t_flags *flags, t_var *var, va_list *ap, t_uint8 *str)
{
	static int	(*len_x[7])();

	if (len_x[0] == NULL)
		init_len_x(len_x);
	return (len_x[flags->conv](flags, var, ap, str));
}

int			pf_sp_x(t_flags *flags, t_var *var, va_list *ap, t_uint8 *str)
{
	char		width;
	t_uint32	d;

	d = va_arg(*ap, t_uint32);
	if (d == 0 && flags->precision == 0)
		return (pf_empty_x(flags, var, str));
	width = dinitialise(flags, d);
	if (!flags->minus)
	{
		if (flags->zero && !flags->isp)
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