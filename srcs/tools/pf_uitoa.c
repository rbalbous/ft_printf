/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:28:48 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/30 16:51:47 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_uintlen(uintmax_t n, int base)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

void	pf_uitoa_base(uintmax_t n, int base, t_flags *flags, t_var *var)
{
	char		toa[flags->len];
	char		str[flags->len + (flags->len / 3)];
	uintmax_t	tn;
	int			i;
	int			j;
	size_t		count;

	i = 0;
	j = 0;
	if (n == 0)
		return (addchar('0', var));
	count = flags->len;
	tn = n;
	while (count-- > 0)
	{
		toa[count] = tn % base + 48;
		tn /= base;
	}
	if (!flags->tsep)
		addstr(toa, var);
	else
	{
		ft_printf("%d\n", flags->len + (flags->len / 3));
		while (i < flags->len + (flags->len / 3))
		{
			if (i % 4 == 0 && i != 0)
				str[flags->len + (flags->len / 3) - i] = flags->tsep;
			else
			{
				str[flags->len + (flags->len / 3) - i] = toa[flags->len - j];
				j++;
			}
			i++;
		}
		addstr(str, var);
	}
}
