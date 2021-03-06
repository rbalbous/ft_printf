/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:29:13 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/07 19:19:35 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if ((str = (char*)malloc(sizeof(str) * (len_s1 + len_s2) + 1)) == 0)
		return (NULL);
	ft_strcpy(str, s1);
	while (len_s2 > i)
	{
		str[len_s1 + i] = s2[i];
		i++;
	}
	str[len_s1 + i] = 0;
	return (str);
}
