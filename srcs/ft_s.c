/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:44 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/03 16:16:36 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s(t_flags *flags, t_var *var, const char *str, va_list *ap)
{
	(void)str;
	char	*tmp;

	tmp = va_arg(*ap, char*);
	if (flags->precision != -1 && (size_t)flags->precision < ft_strlen(tmp))
		tmp[flags->precision] = 0;
	if ((size_t)flags->fwidth > ft_strlen(tmp))
		flags->fwidth -= ft_strlen(tmp);
	else
		flags->fwidth = 0;
	if (flags->fwidth != 0 && flags->minus == 0)
		addwp(flags, var, 'f');
	addstr(tmp, var);
	if (flags->fwidth != 0 && flags->minus == 1)
		addwp(flags, var, 'f');
	return (0);
}
