/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hashtag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:40 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/12 17:49:27 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_hashtag(t_flags *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hashtag = 1;
	return (1);
}
