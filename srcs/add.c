/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:33:39 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/13 15:16:13 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		addnull(t_var *var)
{
	var->buf[var->bufindex] = '(';
	var->bufindex++;
	var->buf[var->bufindex] = 'n';
	var->bufindex++; 
	var->buf[var->bufindex] = 'u';
	var->bufindex++;
	var->buf[var->bufindex] = 'l';
	var->bufindex++;
	var->buf[var->bufindex] = 'l';
	var->bufindex++;
	var->buf[var->bufindex] = ')';
	var->bufindex++;
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

void	addstr(const char *str, t_var *var)
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

void	addnstr(const char *str, size_t len, t_var *var)
{
	size_t i;
	
	i = 0;
	while (len > i)
	{
		var->buf[var->bufindex] = str[i];
		i++;
		var->bufindex++;
	}
	return ;
}
