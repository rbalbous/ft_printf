/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:17:57 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/12 17:38:27 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_flags(t_flags *flags)
{ 
	flags->minus = 0;
	flags->plus = 0;
	flags->hashtag = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->isw = 0;
	flags->isp = 0;
	flags->precision = -1;
	flags->fwidth = 0;
	flags->capx = 0;
	flags->conv = none;
}

int		parse(const char *str, t_var *var, va_list *ap, int (*f[256])())
{
	t_flags flags;

	initialise_flags(&flags);
	while (str[var->index])
	{
		if (f[(int)str[var->index]](&flags, var, ap, str) == 0)
			return (1);
		var->index++;
	}
	return (0);
}
