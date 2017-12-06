/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 21:52:38 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/08 16:28:41 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(*str) * len + 1)) == 0)
		return (NULL);
	ft_memset(str, 0, len + 1);
	return (str);
}
