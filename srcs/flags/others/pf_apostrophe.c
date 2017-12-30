/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apostrophe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 15:21:08 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/30 15:44:18 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_apostrophe(t_flags *flags)
{
	struct lconv	*apopo;

	apopo = localeconv();
	flags->dpt = apopo->decimal_point[0];
	flags->tsep = apopo->thousands_sep[0];
	printf("%c\n", flags->dpt);
	printf("%c\n", flags->tsep);
	return(1);
}
