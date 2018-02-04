/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:21:11 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/04 22:17:34 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countprec(t_flags *flags, char *str)
{
	int		i;

	i = 15 + flags->bigl;
	if (flags->isp)
	{
		flags->len = flags->precision + 3;
		return (flags->precision + 3);
	}
	while (str[i] == '0')
		i--;
	i += 1 * (i != 0);
	flags->len = i;
	return (i);
}

char		*pf_ftoa_hexa(double n, t_flags *flags)
{
	char			*str;
	int				i;
	static char		modu[16];
	int				flag;

	i = 2;
	if (!modu[0])
		pf_initoa(modu);
	if (!(str = ft_memalloc(flags->precision + 3)))
		return (NULL);
	str[0] = '1' - (n == 0);
	if (flags->dpt == 0)
		flags->dpt = '.';
	str[1] = flags->dpt * (flags->precision > 0);
	while (i < flags->precision + 3)
	{
		n = (n - (intmax_t)n) * 16 * (-2 * (n < 0) + 1);
		flag = flags->capx * (((intmax_t)n & 15) > 9 && i != 0);
		str[i] = modu[(intmax_t)n] - flag * 32;
		ft_printf("%c\n", str[i]);
		i++;
	}
	countprec(flags, str);
	return (str);
}

int			pf_fltoa_hexa(long double n, t_flags *flags, t_var *var)
{
	char			*str;
	int				i;
	static char		modu[16];
	int				flag;

	i = 1;
	if (!modu[0])
		pf_initoa(modu);
	if (!(str = ft_memalloc(flags->precision + 2)))
		return (-1);
	if (flags->dpt == 0)
		flags->dpt = '.';
	str[0] = flags->dpt * (flags->precision > 0);
	while (i < flags->precision + 2)
	{
		n = (n - (intmax_t)n) * 16 * (-2 * (n < 0) + 1);
		flag = flags->capx * (((intmax_t)n & 15) > 9 && i != 0);
		str[i] = modu[(intmax_t)n] - flag * 32;
		i++;
	}
	str[i] = 0;
	addnstr(str, countprec(flags, str), var);
	free(str);
	return (0);
}
