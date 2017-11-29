/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:51:37 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/28 18:13:11 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		create(char c, t_var *var, t_flags *flags)
{
	var->index = 0;

	printf("minus : %d\nplus : %d\nhashtag : %d\nspace : %d\nzero : %d\nprecision : %d\nfwidth : %d\nchar : %c\n", flags->minus, flags->plus, flags->hashtag, flags->space, flags->zero, flags->precision, flags->fwidth, c);
}
