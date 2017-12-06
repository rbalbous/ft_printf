/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:35:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/06 15:27:53 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c(t_flags *flags, t_var *var, const char *str, va_list *ap)
{
	(void)str;
	char c;

	c = va_arg(*ap, int);
	if (flags->isw == 1)
		flags->fwidth -= 1;
	if (flags->isw == 1 && flags->minus == 0)
		addwp(flags, var, 'f');
	addchar(c, var);
	if (flags->isw == 1 && flags->minus == 1)
		addwp(flags, var, 'f');
	return (0);
}
