/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 22:08:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/20 17:50:38 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ftoa(double n, t_flags *flags, t_var *var)
{
	char	str[flags->precision + 1];
	int		i;

	i = 0;
	n = (n > 0) ? n : -n;
	pf_itoa(-(intmax_t)n, flags, var);
	addchar('.', var);
	n -= (intmax_t)n;
	while (i < flags->precision + 1)
	{
		n = (n - (intmax_t)n) * 10;
		str[i] = (intmax_t)n + '0';
		i++;
	}
	str[i] = 0;
	addstr(str, var);
}
