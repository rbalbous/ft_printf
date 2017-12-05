/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addwp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:55:35 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/05 17:20:35 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wandp(t_flags *flags, t_var *var)
{
	if (flags->fwidth != 0 && flags->precision != -1)
	{
		if (flags->fwidth > flags->precision)
			flags->fwidth -= flags->precision;
		else
			flags->fwidth = 0;
	}
	if (flags->fwidth != 0)
		addwp(flags, var, 'f');
	if (flags->precision != -1)
		addwp(flags, var, 'p');
	return (1);
}

int		addwp(t_flags *flags, t_var *var, char n)
{
	if (n == 'f')
	{
		while (flags->fwidth > 0)
		{
			addchar(' ', var);
			flags->fwidth--;
		}
	}
	else if (n == 'p')
	{
		while (flags->precision > 0)
			{
				addchar('0', var);
				flags->precision--;
			}
	}
	return (1);
}
