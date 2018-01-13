/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_m.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:35:57 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/13 21:01:35 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     pf_m(t_flags *flags, t_var *var, va_list ap)
{
    int     *d;
    int     i;
    int     count;
    char    str[flags->precision * 3];
    
    i = 0;
    count = 0;
    d = va_arg(ap, int*);
    while (i < flags->precision)
    {
        ft_sprintf((str + count), "%02hhX", d[i]);
        ft_sprintf((str + count + 2), " ");
        i++;
        count += 3;
    }
    addnstr(str, flags->precision * 3 - 1, var);
    return (0);
}
