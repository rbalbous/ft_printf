/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:42:24 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/01 11:40:12 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_memcpy(void *dest, const void *src, int n)
{
	char	*dd;
	char	*ss;
	int		i;

	i = 0;
	dd = (char*)dest;
	ss = (char*)src;
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	dd[n] = 0;
	return (n);
}
