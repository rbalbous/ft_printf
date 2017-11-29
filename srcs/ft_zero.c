/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:57 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/29 17:29:48 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero(t_flags *flags, t_var *var, const char *format, va_list ap)
{
	if (flags->minus == 1)
		return (0);
	flags->zero = 1;
	return (1);
}
