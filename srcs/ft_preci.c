/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:39 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/06 15:42:41 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_preci(t_flags *flags, t_var *var, const char *str)
{
	if (str[var->index] == '.')
	{
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
	else
	{
		flags->isw = 1;
		while (str[var->index] && ft_isdigit(str[var->index]) == 1)
		{
			flags->fwidth = flags->fwidth * 10 + (str[var->index] - 48);
			var->index++;
		}
		var->index--;
		return (1);
	}
}
