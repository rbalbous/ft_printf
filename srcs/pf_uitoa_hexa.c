/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uitoa_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:40:24 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/12 22:47:29 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_initoa(char modu[16])
{
	modu[0] = '0';
	modu[1] = '1';
	modu[2] = '2';
	modu[3] = '3';
	modu[4] = '4';	
	modu[5] = '5';
	modu[6] = '6';
	modu[7] = '7';
	modu[8] = '8';
	modu[9] = '9';
	modu[10] = 'a';
	modu[11] = 'b';
	modu[12] = 'c';
	modu[13] = 'd';
	modu[14] = 'e';
	modu[15] = 'f';
}

void	pf_uitoa_hexa(uintmax_t n, int base, t_flags *flags, t_var *var)
{
	char			*str;
	uintmax_t		tn;
	size_t			count;
	static char		modu[16];
	int				flag;

	if (!modu[0])
		pf_initoa(modu);
	if (n == 0)
		return (addchar('0', var));
	count = flags->len;
	if ((str = ft_strnew(count)) == NULL)
		return ;
	tn = n;
	while (count-- > 0)
	{
		flag = flags->capx * (tn % base > 9);
		str[count] = modu[tn % base] - flag * 32;
		tn /= base;
	}
	addstr(str, var);
	free(str);
}
