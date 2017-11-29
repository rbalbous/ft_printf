/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:14:24 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/29 17:39:13 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialis_var(t_var *var)
{
	var->index = 0;
	var->bufindex = 0;
	var->len = 0;
	ft_bzero(var->buf, BUFF_SIZE);
}

void	initialise_f(int (*f[128])(t_flags, t_var, const char*, va_arg))
{
	int		i;

	i = 0;
	while (i < 127)
		f[i++] = ft_error;
	i = 0;
	f['0'] = ft_zero;
	f['.'] = ft_preci;
	f['+'] = ft_plus;
	f['-'] = ft_minus;
	f['#'] = ft_hashtag;
	while (i < 9)
		f['1' + i++] = ft_preci;
	//f['h'] = ft_h;
	//f['l'] = ft_l;
	//f['j'] = ft_j;
	//f['z'] = ft_z;
	return (ft_initialise_conv(void f));
}

void	ft_initialise_conv(int (*f[128])(t_flags, t_var, const char*, va_arg))
{
	//f['s'] = ft_s;
	//f['S'] = ft_cap_s;
	//f['p'] = ft_p;
	//f['d'] = ft_d;
	//f['D'] = ft_cap_d;
	//f['i'] = ft_i;
	//f['o'] = ft_o;
	//f['O'] = ft_cap_o;
	//f['u'] = ft_u;
	//f['U'] = ft_cap_u;
	//f['x'] = ft_x;
	//f['X'] = ft_cap_x;
	//f['c'] = ft_c;
	//f['C'] = ft_cap_c;
	return ;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_var	var;
	int		(*f[128])(t_flags, t_var, const char*, va_arg);

	if (!format)
		return ;
	initialise_var(&var);
	initialise_f(f(;
	while (format[var.index])
	{
		if (format[var.index] == '%' && format[var.index + 1])
				parse(format, &var, ap, f);
		else
			addchar(format[var.index], &var);
		var.index++;
	}
	va_end(ap);
	return (0);
}
