/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:00 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/16 18:59:52 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_one(t_flags *flags, t_var *var, char c)
{
	char	width;
	
	(void)var;
	printf("1\n");
	width = ' ' + 16 * (flags->zero);
	flags->fwidth -=  1;
	flags->fwidth *= (flags->fwidth > 0);
	if (flags->minus == 0)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addchar(c, var);
	}
	else
	{
		addchar(c, var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}

static int		wsize(wint_t c, t_flags *flags, t_var *var)
{
	if ((c | 0x7F) == 0x7F)
		len_one(flags, var, (char)c);
	else if (c <= 0x07FF)
	{
		flags->len = 2;
	}
	else if (c <= 0xFFFF)
	{
		flags->len = 3;
	}
	else if (c <= 0x10FFFF)
	{
		flags->len = 4;
	}
	return (0);
}

int		pf_cap_c(t_flags *flags, t_var *var, va_list *ap)
{
	wint_t			c;
	unsigned int	byte;

	c = va_arg(*ap, wint_t);
	wsize(c, flags, var);
	if (!((c >> 7) + ((MB_CUR_MAX) == 1)))
		len_one(flags, var, (char)c);
	if (flags->len == 2)
	{
		byte = (((c & 0x3F) << 8) | (c & 0x7F));
		addnstr(&byte, 2, var);
	}
	return (0); 
}
/*
1100 1011      1011 1000
0110 0101      1101 1100
0011 1111      0111 1111
*/
