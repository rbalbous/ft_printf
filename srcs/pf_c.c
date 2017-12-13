/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:35:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/12 16:21:01 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_c(t_flags *flags, t_var *var, va_list *ap)
{
	char	c;
	char	width;

	c = va_arg(*ap, int);
	width = ' ' + 16 * (flags->zero);
	flags->fwidth -= 1;
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
