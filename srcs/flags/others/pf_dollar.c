/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:44:11 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_dollar(t_flags *flags, t_var *var, va_list ap)
{
	int		len;

	len = flags->fwidth - (1 * (flags->fwidth > 0));
	va_copy(ap, flags->begin);
	while (len-- > 0)
		va_arg(ap, int);
	var->index++;
	return (1);
}
