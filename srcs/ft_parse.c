/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:17:57 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/29 18:21:38 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->hashtag = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->fwidth = 0;
	flags->length = none;
}

void	parse(const char *str, t_var *var, va_list ap
		, void (*f[128])(t_flags, t_var, const char*, va_arg))
{
	t_flags flags;
	
	initialise_flags(&flags);
	while (str[var->index])
	{
		f[str[var->index]](flags, var, format, ap);
		
	}
}
