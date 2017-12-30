/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:17:57 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/30 15:37:52 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_initflags(t_flags *flags, va_list *ap)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->hashtag = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->quote = 0;
	flags->isp = 0;
	flags->isw = 0;
	flags->precision = -1;
	flags->fwidth = 0;
	va_copy(flags->begin, *ap);
	flags->capx = 0;
	flags->cast = ' ';
	flags->tsep = 0;
	flags->dpt = 0;
	flags->len = 0;
	flags->conv = none;
	return (0);
}

int		parse(t_uint8 *str, t_var *var, va_list *ap, int (*f[256])())
{
	t_flags flags;
	int		ret;

	pf_initflags(&flags, ap);
	var->index++;
	while (str[var->index])
	{
		if ((ret = f[(int)str[var->index]](&flags, var, ap, str)) <= 0)
			return (ret);
		var->index++;
	}
	return (-2);
}
