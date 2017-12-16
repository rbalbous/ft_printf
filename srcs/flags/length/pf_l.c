/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:24:42 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/12 18:21:07 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_l(t_flags *flags, t_var *var, va_list *ap, const char *str)
{
	(void)ap;
	if (flags->conv > l)
		return (1);
	if (flags->conv == l && str[var->index - 1] == 'l')
	{
		flags->conv = ll;
		return (1);
	}
	flags->conv = l;
	return (1);
}
