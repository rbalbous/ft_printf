/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addwp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:55:35 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/06 18:12:02 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wandp(t_flags *flags, t_var *var)
{
	if (flags->isw == 1 && flags->isp == 1)
	{
		if (flags->fwidth > flags->precision)
			flags->fwidth -= flags->precision;
		else
			flags->isw = 0;
	}
	if (flags->isw == 1)
		addwp(flags, var, 'f');
	if (flags->isp == 1)
		addwp(flags, var, 'p');
	return (1);
}

int		addwp(t_flags *flags, t_var *var, char n)
{
	int wid;
	int pre;

	wid = flags->fwidth;
	pre = flags->precision;
	if (n == 'f')
	{
		while (wid> 0)
		{
			addchar(' ', var);
			wid--;
		}
		flags->isw = 0;
	}
	else if (n == 'p')
	{
		while (pre > 0)
			{
				addchar('0', var);
				pre--;
			}
			flags->isp = 0;
	}
	return (1);
}
