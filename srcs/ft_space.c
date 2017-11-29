/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:10:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/29 17:29:41 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_space(t_flags *flags, t_var *var, const char *format, va_list ap)
{
	(void)var;
	(void)ap;
	(void)format;
	flags->space = 1;
	return (0);
}
