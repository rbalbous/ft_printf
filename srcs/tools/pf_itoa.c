/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:00:03 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/13 16:19:15 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_intlen(intmax_t n, int base)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

void	pf_itoa(intmax_t n, t_flags *flags, t_var *var)
{
	char		*str;
	intmax_t	tn;
	size_t		count;

	if (n == 0)
		return (addchar('0', var));
	count = flags->len;
	if ((str = ft_strnew(count)) == NULL)
		return ;
	tn = n;
	while (count-- > 0)
	{
		str[count] = -(tn % 10) + 48;
		tn /=	10;
	}
	addstr(str, var);
	free(str);
}
