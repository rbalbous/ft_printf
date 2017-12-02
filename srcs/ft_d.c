/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:34 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/02 20:09:23 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d(t_flags *flags, t_var *var, const char *str, va_list *ap)
{
	int	d;

	d = va_arg(*ap, int);
	if (flags->precision != 0 || flags->fwidth != 0)
		pandw(flags, var, f);
	if (flags->plus = 1 && d >= 0)
		addchar('+', var);
	
}
