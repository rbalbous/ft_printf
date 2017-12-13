/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:28:48 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/13 16:19:18 by rbalbous         ###   ########.fr       */
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
	char		*str;
	uintmax_t	tn;
	size_t		count;

	if (n == 0)
		return (addchar('0', var));
	count = flags->len;
	if ((str = ft_strnew(count)) == NULL)
		return ;
	tn = n;
	while (count-- > 0)
	{
		str[count] = tn % base + 48;
		tn /= base;
	}
	addstr(str, var);
	free(str);
}
