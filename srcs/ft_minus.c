/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:20 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/29 17:29:17 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_minus(t_flags *flags, t_var *var, const char *format, va_list ap)
{
	if (flags->zero == 1)
		flags->zero = 0;
	flags->minus = 1;
	return (0);
}
