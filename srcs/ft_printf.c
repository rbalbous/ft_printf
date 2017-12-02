/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:14:24 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/02 17:35:11 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_var(t_var *var)
{
	var->index = 0;
	var->bufindex = 0;
	var->len = 0;
	ft_bzero(var->buf, BUFF_SIZE);
}

static void	init_conv(int (*f[256])())
{
	f['%'] = percent;
	f['s'] = ft_s;
	f['c'] = ft_c;
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
	//f['C'] = ft_cap_c;
}

static void	init_flags(int (*f[256])())
{
	int		i;

	i = 0;
	while (i < 256)
	{
		f[i] = ft_error;
		i++;
	}
	i = 0;
	f['0'] = ft_zero;
	f['.'] = ft_preci;
	f['+'] = ft_plus;
	f['-'] = ft_minus;
	f['#'] = ft_hashtag;
	while (i < 9)
	{
		f['1' + i] = ft_preci;
		i++;
	}
	//f['h'] = ft_h;
	//f['l'] = ft_l;
	//f['j'] = ft_j;
	//f['z'] = ft_z;
}

int		ft_printf(const char *str, ...)
{
	static int	(*f[256])() = {NULL};
	va_list		ap;
	t_var		var;

	if (!str)
		return (0);
	if (f[0] == NULL)
	{
		init_flags(f);
		init_conv(f);
	}
	initialise_var(&var);
	va_start(ap, str);
	while (str[var.index])
	{
		if (str[var.index] == '%' && str[var.index + 1])
		{
			var.index++;
			parse(str, &var, &ap, f);
		}
		else
			addchar(str[var.index], &var);
		var.index++;
	}
	va_end(ap);
	write(1, var.buf, var.bufindex);
	return (var.bufindex);
}
