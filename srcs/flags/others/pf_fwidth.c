/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fwidth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:47:30 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/30 14:58:10 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_fwidth(t_flags *flags, t_var *var, va_list *ap, t_uint8 *str)
{
	(void)ap;
	int		tmp;

	tmp = flags->fwidth;
	flags->isw = 1;
	flags->fwidth = 0;
	while (str[var->index] && ft_isdigit(str[var->index]) == 1)
	{
		flags->fwidth = flags->fwidth * 10 + (str[var->index] - 48);
		var->index++;
	}
	if (str[var->index] == '$')
	{
		pf_dollar(flags, var, ap);
		flags->fwidth = tmp;
	}
	var->index--;
	return (1);
}
