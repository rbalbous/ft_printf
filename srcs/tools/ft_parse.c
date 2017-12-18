/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:17:57 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/18 18:56:42 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(unsigned char *str, t_var *var, va_list *ap, int (*f[256])())
{
	t_flags flags;
	int		ret;

	flags = (t_flags){0, 0, 0, 0, 0, 0, 0, -1, 0, 0, ' ', 0, none};
	var->index++;
	while (str[var->index])
	{
		if ((ret = f[(int)str[var->index]](&flags, var, ap, str)) == 0)
			return (ret);
		var->index++;
	}
	return (-2);
}
