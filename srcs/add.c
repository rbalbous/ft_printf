/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:33:39 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/28 15:03:42 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	addchar(const char c, t_var *var)
{
	var->buf[var->bufindex] = c;
	var->bufindex++;
	return ;
}

void	addstr(const char *str, size_t len, t_var *var)
{
	while (len > 0)
	{
		var->buf[var->bufindex] = str[var->index - len];
		len--;
		var->bufindex++;
	}
	return ;
}
