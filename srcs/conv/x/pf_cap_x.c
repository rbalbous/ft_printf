/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:31 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/12 14:52:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_cap_x(t_flags *flags, t_var *var, va_list *ap)
{
	flags->capx = 1;
	pf_x(flags, var, ap);
	return (0);
}
