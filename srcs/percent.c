/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:12:18 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/03 16:09:24 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent(t_flags *flags, t_var *var, const char *str)
{
	int		ind;

	ind = 1;
	while (str[var->index + ind] && (str[var->index + ind] != '%'))
		ind++;
	if (flags->fwidth > ind)
		flags->fwidth -= ind;
	else
		flags->fwidth = 0;
	if (flags->fwidth != 0 && flags->minus == 0)
		addwp(flags, var, 'f');
	while (ind-- > 0)
	{
		addchar(str[var->index], var);
		var->index++;
	}
	if (flags->fwidth != 0 && flags->minus == 1)
		addwp(flags, var, 'f');
	var->index--;
	return (0);
}
