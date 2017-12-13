/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fwidth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:47:30 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/13 14:52:46 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_fwidth(t_flags *flags, t_var *var, va_list *ap, const char *str)
{
	(void)ap;
	flags->isw = 1;
	while (str[var->index] && ft_isdigit(str[var->index]) == 1)
	{
		flags->fwidth = flags->fwidth * 10 + (str[var->index] - 48);
		var->index++;
	}
	var->index--;
	return (1);
}
