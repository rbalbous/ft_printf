/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addwp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:55:35 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/02 20:09:13 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wandp(t_flags *flags, t_var *var)
{
	if (flags->fwidth && flags->precision)
	{
		if (flags->fwidth > flags->precision)
			flags->fwidth -= flags->precision;
		else
			flags->fwidth = 0; 
	}
	else if (flags->fwidth != 0)
		addwp(flags, var, f)
}

int		addwp(t_flags *flags, t_var *var, char n)
{
	char c;
	if (n = 'f')
	{
		while (flags->fwidth > 0)
		{
			addchar(' ', var);
			flags->fwidth--;
		}
	}
	else if (n = 'p')
	{
		while (flags->fwidth > 0)
			{
				addchar(' ', var);
				flags->fwidth--;
			}
	}
	return (1);
}
