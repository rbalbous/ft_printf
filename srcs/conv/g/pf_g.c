/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_g.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:42:14 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/03 23:09:13 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_g(t_flags *flags, t_var *var, va_list *ap)
{
	double		d;
	int			count;

	(void)var;
	count = 0;
	d = va_arg(*ap, double);
	flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
	if ((intmax_t)d == 0)
	{
		flags->precision += (!flags->isp) * 7 - 1;
		while ((intmax_t)d == 0)
		{
			d *= 10;
			count++;
		}
		ft_printf("%f | %d\n", d, count);
		if (count > 4)
			pf_spe_e(flags, var, d, -count);
	}
	return (0);
}
