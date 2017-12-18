/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:09:57 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/18 18:09:48 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_empty_d(t_flags *flags, t_var *var)
{
	flags->fwidth -= (flags->plus);
	if (flags->minus)
	{
		if (flags->plus)
			addchar('+', var);
		flags->fwidth = addmchar(' ', var, flags->fwidth);
	}
	else
	{
		flags->fwidth = addmchar(' ', var, flags->fwidth);
		if (flags->plus)
			addchar('+', var);
	}
	return (0);
}

int		pf_empty_o(t_flags *flags, t_var *var)
{
	flags->fwidth -= flags->hashtag;
	if (flags->minus)
	{
		if (flags->hashtag)
			addchar('0', var);
		flags->fwidth = addmchar(' ', var, flags->fwidth);
	}
	else
	{
		flags->fwidth = addmchar(' ', var, flags->fwidth);
		if (flags->hashtag)
			addchar('0', var);
	}
	return (0);
}

int		pf_empty_u(t_flags *flags, t_var *var)
{
	flags->fwidth = addmchar(' ', var, flags->fwidth);
	return (0);
}

int		pf_empty_x(t_flags *flags, t_var *var, unsigned char *str)
{
	flags->fwidth -= (str[var->index] == 'p') * 2;
	if (flags->minus)
	{
		if (str[var->index] == 'p')
			addstr("0x", var);
		flags->fwidth = addmchar(' ', var, flags->fwidth);
	}
	else
	{
		flags->fwidth = addmchar(' ', var, flags->fwidth);
		if (str[var->index] == 'p')
			addstr("0x", var);
	}
	return (0);
}

int		pf_empty_s(t_flags *flags, t_var *var)
{
	char	width;

	width = ' ' + (flags->zero) * 16;
	flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}
