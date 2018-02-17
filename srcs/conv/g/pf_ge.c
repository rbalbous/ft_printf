/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:26:17 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/17 19:53:47 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_aground(char *str, t_flags *flags, long double d)
{
	if (*str >= '5')
	{
		while (*(--str) == '9')
			flags->len--;
		if (*str != '.')
		{
			*str += 1;
		}
		else
		{
			*(--str) += 1;
			if (!flags->hashtag)
				flags->len--;
		}
	}
	else if (flags->len == 2 && (!((intmax_t)d == 0
	&& flags->hashtag && flags->precision != 0)))
		flags->len--;
	return (0);
}

static int	pf_create(t_var *var, int count)
{
	addchar('e', var);
	if (count < 0)
	{
		addchar('-', var);
		count *= -1;
	}
	else
		addchar('+', var);
	if (count < 10)
		addchar('0', var);
	addstr(ft_itoa(count), var);
	return (0);
}

int		pf_ge(t_flags *flags, t_var *var, long double d, int count)
{
	char	*num;
	int		lenct;

	flags->precision += (!flags->isp) * 7 - 1;
	flags->precision *= (flags->precision > 0);
	flags->len = flags->precision + 2;
	if ((num = pf_ftostr(d, flags)) == NULL)
		return (-1);
	//ft_printf("%s %c %d\n", num, num[flags->len], flags->len);
	pf_aground(num + flags->len, flags, d);
	//ft_printf("%s %d\n", num, flags->len);
	lenct = pf_intlen(count, 10) - 1;
	//ft_printf("%d\n", lenct);
	flags->fwidth -= flags->len + lenct + (lenct < 10) + 2
	+ (d < 0 || flags->space || flags->plus);
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
		pf_create(var, count);
	}
	else
	{
		pf_addminp(flags, var, d);
		addnstr(num, flags->len, var);
		pf_create(var, count);
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	}
	return (0);
}
