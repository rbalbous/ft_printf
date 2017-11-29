/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:34 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/29 17:29:26 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_plus(t_flags *flags, t_var *var, const char *format, va_list ap)
{
	if (flags->space == 1)
		flags->space = 0;
	flags->plus = 1;
	return (1);
}
