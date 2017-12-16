/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:17:57 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/16 18:40:47 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(unsigned char *str, t_var *var, va_list *ap, int (*f[256])())
{
	t_flags flags;

	flags = (t_flags){0, 0, 0, 0, 0, 0, 0, -1, 0, 0, ' ', 0, none};
	//initialise_flags(&flags);
	while (str[var->index])
	{
		if (f[(int)str[var->index]](&flags, var, ap, str) == 0)
			return (1);
		var->index++;
	}
	return (0);
}
