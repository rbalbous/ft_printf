/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:24:19 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialise_var(t_var *var)
{
	var->index = -1;
	var->bufindex = 0;
	ft_bzero(var->buf, BUFF_SIZE);
}

static void	init_conv(int (*f[256])())
{
	f['s'] = pf_s;
	f['c'] = pf_c;
	f['S'] = pf_cap_s;
	f['p'] = pf_lx;
	f['d'] = pf_d;
	f['D'] = pf_cap_d;
	f['i'] = pf_d;
	f['o'] = pf_o;
	f['O'] = pf_cap_o;
	f['u'] = pf_u;
	f['U'] = pf_cap_u;
	f['x'] = pf_x;
	f['X'] = pf_cap_x;
	f['C'] = pf_cap_c;
	f['%'] = pf_percent;
	f['*'] = pf_wildcard;
	f['b'] = pf_b;
	f['f'] = pf_f;
	f['F'] = pf_cap_f;
	f['n'] = pf_n;
	f['e'] = pf_e;
	f['E'] = pf_cap_e;
	f['$'] = pf_dollar;
	f['\''] = pf_apostrophe;
	f['g'] = pf_g;
}

static void	init_flags(int (*f[256])())
{
	int		i;

	i = -1;
	while (++i < 256)
		f[i] = pf_percent;
	i = -1;
	f['0'] = ft_zero;
	f['.'] = ft_preci;
	f['+'] = ft_plus;
	f['-'] = ft_minus;
	f['#'] = pf_hashtag;
	f[' '] = ft_space;
	while (++i < 9)
		f['1' + i] = pf_fwidth;
	f['h'] = pf_h;
	f['l'] = pf_l;
	f['j'] = ft_j;
	f['z'] = pf_z;
	f['a'] = pf_a;
	f['A'] = pf_cap_a;
	init_conv(f);
}

int			ft_sprintf(char *dest, const char *str, ...)
{
	static int	(*f[256])() = {NULL};
	va_list		ap;
	t_var		var;
	int			ret;

	if (f[0] == NULL)
		init_flags(f);
	initialise_var(&var);
	va_start(ap, str);
	while (str[++var.index])
	{
		if (str[var.index] == '%' && str[var.index + 1])
		{
			if ((ret = parse((t_uint8*)str, &var, ap, f)) < 0)
			{
				if (ret == -2)
					break ;
				return (-1);
			}
		}
		else if (str[var.index] != '%')
			addchar(str[var.index], &var);
	}
	va_end(ap);
	return (pf_memcpy(dest, var.buf, var.bufindex));
}
