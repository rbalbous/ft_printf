/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:33:39 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/01 12:25:13 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		addnull(t_flags *flags, t_var *var)
{
	int n;

	n = 6;
	if (flags->precision < 6 && flags->isp)
		n = flags->precision;
	addnstr("(null)", n, var);
	return (0);
}

int		addmchar(char c, t_var *var, int len)
{
	while (len-- > 0)
	{
		var->buf[var->bufindex] = c;
		var->bufindex++;
	}
	return (0);
}

void	addchar(const char c, t_var *var)
{
	var->buf[var->bufindex] = c;
	var->bufindex++;
	return ;
}

void	addstr(char *str, t_var *var)
{
	int i;

	i = 0;
	while (str[i])
	{
		var->buf[var->bufindex] = str[i];
		var->bufindex++;
		i++;
	}
	return ;
}

void	addnstr(void *str, size_t len, t_var *var)
{
	size_t	i;
	char	*tmp;

	tmp = str;
	i = 0;
	while (len > i)
	{
		var->buf[var->bufindex] = tmp[i];
		i++;
		var->bufindex++;
	}
	return ;
}
