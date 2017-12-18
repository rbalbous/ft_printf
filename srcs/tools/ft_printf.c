/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:14:24 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/18 19:00:21 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initialise_var(t_var *var)
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
}

static void	init_flags(int (*f[256])())
{
	int		i;

	i = 0;
	while (i < 256)
	{
		f[i] = pf_percent;
		i++;
	}
	i = 0;
	f['0'] = ft_zero;
	f['.'] = ft_preci;
	f['+'] = ft_plus;
	f['-'] = ft_minus;
	f['#'] = pf_hashtag;
	f[' '] = ft_space;
	while (i < 9)
	{
		f['1' + i] = pf_fwidth;
		i++;
	}
	f['h'] = pf_h;
	f['l'] = pf_l;
	f['j'] = ft_j;
	f['z'] = pf_z;
	init_conv(f);
}

int			ft_printf(const char *str, ...)
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
			if ((ret = parse((unsigned char*)str, &var, &ap, f)) < 0)
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
	return (write(1, var.buf, var.bufindex));
}
