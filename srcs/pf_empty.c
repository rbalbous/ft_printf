/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:09:57 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/13 19:37:11 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_empty(t_flags *flags, t_var *var)
{	
	char	width;

	width = ' ' + 16 * (flags->zero);
	flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}
