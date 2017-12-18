/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:12:18 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/18 18:09:37 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_percent(t_flags *flags, t_var *var, va_list *ap, unsigned char *str)
{
	char	width;
	char	c;

	(void)ap;
	c = str[var->index];
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
