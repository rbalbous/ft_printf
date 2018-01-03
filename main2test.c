/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/03 23:12:45 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>
#include <locale.h>
#include <langinfo.h>
#include <nl_types.h>

int		main(void)
{
	int i;
	int j;
	double z = 2.99999;

	setlocale(LC_ALL, "");
	i = ft_printf("%C", 0x11ffff);
	j = printf("%C", 0x11ffff);
	printf("%d %d", i, j);
	printf("%.2g\n", 654248.235);
	printf("%.2g\n", 654235.235); 
	ft_printf("%'u\n", 2345678);
	printf("%'u\n", 2345678); 
	ft_printf("{%'6.5u}\n", 2500);
	printf("{%'6.5u}\n", 2500);
	ft_printf("--------\n");
	ft_printf("{%-'6.5u}\n", 2500);
	printf("{%-'6.5u}\n", 2500);
	ft_printf("--------\n");
	ft_printf("{%'5.4u}\n", 2500);
	printf("{%'5.4u}\n", 2500);
	ft_printf("--------\n");
	ft_printf("{%'5.2u}\n", 2500);
	printf("{%'5.2u}\n", 2500);
	ft_printf("--------\n");
	ft_printf("{%'.2u}\n", 2500);
	printf("{%'.2u}\n", 2500);
	ft_printf("--------\n");
	ft_printf("{%'u}\n", UINT_MAX);
	printf("{%'u}\n", UINT_MAX);
	ft_printf("--------\n");
	ft_printf("{%'hu}\n", USHRT_MAX);
	printf("{%'hu}\n", USHRT_MAX);
	ft_printf("--------\n");
	ft_printf("{%'hhu}\n", UCHAR_MAX);
	printf("{%'hhu}\n", UCHAR_MAX);
	ft_printf("--------\n");
	ft_printf("{%'lu}\n", ULONG_MAX);
	printf("{%'lu}\n", ULONG_MAX);
	ft_printf("--------\n");
	ft_printf("{%'llu}\n", ULLONG_MAX);
	printf("{%'llu}\n", ULLONG_MAX);
	ft_printf("--------\n");
	ft_printf("{%'zu}\n", SIZE_T_MAX);
	printf("{%'zu}\n", SIZE_T_MAX);
	ft_printf("--------\n");
	ft_printf("{%'ju}\n", 2500);
	printf("{%'ju}\n", 2500);
	ft_printf("--------\n");
	ft_printf("{%'40lo}\n", ULONG_MAX);
	printf("{%'40lo}\n", ULONG_MAX);
	ft_printf("--------\n");
	ft_printf("{%'15d}\n", INT_MIN);
	printf("{%'15d}\n", INT_MIN);
	ft_printf("--------\n");
	ft_printf("{%'f}\n", 123456.123);
	printf("{%'f}\n", 123456.123);
	ft_printf("--------\n");
	ft_printf("{%'16f}\n", 123456.123);
	printf("{%'16f}\n", 123456.123);
	ft_printf("--------\n");
	ft_printf("{% f}\n", -INFINITY);
	printf("{% f}\n", -INFINITY);
	ft_printf("--------\n");
	ft_printf("{%+f}\n", NAN);
	printf("{%+f}\n", NAN);
	ft_printf("--------\n");
	ft_printf("{%12f}\n", -INFINITY);
	printf("{%12f}\n", -INFINITY);
	ft_printf("--------\n");
	ft_printf("{%12F}\n", -INFINITY);
	printf("{%12F}\n", -INFINITY);
	ft_printf("--------\n");
	ft_printf("{%12F}\n", NAN);
	printf("{%12F}\n", NAN);
	ft_printf("--------\n");
	ft_printf("{%-12f}\n", -INFINITY);
	printf("{%-12f}\n", -INFINITY);
	ft_printf("--------\n");
	ft_printf("%.12g\n", .0000123456);
	printf("%.12g\n", 126.56);
	return (0);
}
