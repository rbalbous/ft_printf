/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_gf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:21:22 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/17 19:51:55 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_gf(t_flags *flags, t_var *var, long double d)
{
	char	*num;

	flags->precision += (!flags->isp) * 7 - 1;
	flags->precision *= (flags->precision > 0);
	flags->len = flags->precision + 2;
	if ((num = pf_ftostr(d, flags)) == NULL)
		return (-1);
	//ft_printf("%s %c %d\n", num, num[flags->len], flags->len);
	pf_aground(num + flags->len, flags, d);
	//ft_printf("%s %d\n", num, flags->len);
	flags->fwidth -= flags->len + (d < 0 || flags->space || flags->plus);
	flags->fwidth *= (flags->fwidth > 0);
	if (!flags->minus)
	{
		if (flags->zero)
		{
			pf_addminp(flags, var, d);
			flags->fwidth = addmchar('0', var, flags->fwidth);
		}
		else
		{
			flags->fwidth = addmchar(' ', var, flags->fwidth);
			pf_addminp(flags, var, d);
		}
		addnstr(num, flags->len, var);
	}
	else
	{
		pf_addminp(flags, var, d);
		addnstr(num, flags->len, var);
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	}
	return (0);
}
