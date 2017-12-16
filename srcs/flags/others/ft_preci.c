/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:39 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/13 14:49:10 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_preci(t_flags *flags, t_var *var, va_list *ap, const char *str)
{
	(void)ap;
	flags->precision = 0;
	flags->isp = 1;
	var->index++;
	while (str[var->index] && ft_isdigit(str[var->index]) == 1)
	{
		flags->precision = flags->precision * 10 + (str[var->index] - 48);
		var->index++;
	}
	var->index--;
	return (1);
}
