/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:50:27 by raf               #+#    #+#             */
/*   Updated: 2017/09/28 21:13:22 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *dd;
	char *ss;

	dd = (char*)dest;
	ss = (char*)src;
	while (n-- > 0)
		*(dd++) = *(ss++);
	return (dest);
}
