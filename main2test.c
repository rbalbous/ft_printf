/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/30 16:52:35 by rbalbous         ###   ########.fr       */
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
	double z = 2.99999;

	setlocale(LC_ALL, "");
	/*i = ft_printf("%C", 0x11ffff);
	j = printf("%C", 0x11ffff);
	printf("%d %d", i, j);
	printf("%.2g\n", 654248.235);
	printf("%.2g\n", 654235.235); */
	ft_printf("%'u\n", 234556);
	printf("%'u\n", 234556);
	return (0);
}
