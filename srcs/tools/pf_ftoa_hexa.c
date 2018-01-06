/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:21:11 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/06 16:29:28 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countprec(t_flags *flags, char *str)
{
	int		i;

	i = 13;
	if (flags->isp)
		return (flags->precision + 2);
	while (str[i] == '0')
		i--;
	i += 1 * (i != 0);
	return (i);
}

void		pf_ftoa_hexa(double n, t_flags *flags, t_var *var)
{
	char			str[flags->precision + 2];
	int				i;
	static char		modu[16];
	int				flag;

	i = 1;
	if (!modu[0])
		pf_initoa(modu);
	addchar('1', var);
	if (flags->dpt == 0)
		flags->dpt = '.';
	str[0] = flags->dpt;
	while (i < flags->precision + 2)
	{
		n = (n - (intmax_t)n) * 16 * (-2 * (n < 0) + 1);
		flag = flags->capx * (((intmax_t)n & 15) > 9 && i != 0);
		str[i] = modu[(intmax_t)n] - flag * 32;
		i++;
	}
	str[i] = 0;
	addnstr(str, countprec(flags, str), var);
}
