/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 22:08:43 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/12 18:28:54 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ftoa(long double n, t_flags *flags, t_var *var)
{
	char	str[25];
	int		i;
	int		count;

	i = 1;
	pf_itoa((intmax_t)(n * (2 * (n < 0) - 1)), flags, var);
	if (flags->dpt == 0)
		flags->dpt = '.';
	str[0] = flags->dpt;
	count = flags->precision + 2 + 
	flags->hashtag * (!flags->precision);
	while (i < count)
	{
		n = (n - (intmax_t)n) * 10 * (-2 * (n < 0) + 1);
		str[i] = (intmax_t)n + '0';
		i++;
	}
	str[i] = 0;
	addnstr(str, count, var);
}
