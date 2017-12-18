/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:49:26 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/18 19:21:39 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>
#include <locale.h>

int		main(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	setlocale(LC_ALL, "");
	i = ft_printf("");
	j = printf("");
	ft_printf("%d | %d", i, j);
	return (0);
}
