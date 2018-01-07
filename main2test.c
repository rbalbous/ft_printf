/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/07 12:52:31 by rbalbous         ###   ########.fr       */
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
	double v = -1.0;

	setlocale(LC_ALL, "");
	ft_printf("%C", 0x11ffff);
	printf("%C", 0x11ffff);
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
	ft_printf("{%'.5f}\n", 123456.123);
	printf("{%'.5f}\n", 123456.123);
	ft_printf("--------\n");
	ft_printf("{%'.8f}\n", 123456.123);
	printf("{%'.8f}\n", 123456.123);
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
	ft_printf("%E\n", 00000.1234);
	printf("%E\n", 00000.1234);
	ft_printf("--------\n");
	ft_printf("%g\n", 21234567.5605);
	printf("%g\n", 21234567.5605);
	ft_printf("--------\n");
	ft_printf("%g\n", 2123.5605);
	printf("%g\n", 2123.5605);
	ft_printf("--------\n");
	ft_printf("%g\n", 2123.5655);
	printf("%g\n", 2123.5655);
	ft_printf("--------\n");
	ft_printf("%g\n", 212345.5655);
	printf("%g\n", 212345.5655);
	ft_printf("--------\n");
	ft_printf("%.5g\n", 212345.5655);
	printf("%.5g\n", 212345.5655);
	ft_printf("--------\n");
	ft_printf("%.9g\n", 212345.5655);
	printf("%.9g\n", 212345.5655);
	ft_printf("--------\n");
	ft_printf("%g\n", 0.00000212345675605);
	printf("%g\n", 0.0000021234565605);
	ft_printf("--------\n");
	ft_printf("%.9g\n", 0.00000212345675605);
	printf("%.9g\n", 0.0000021234565605);
	ft_printf("--------\n");
	ft_printf("%.5g\n", 0.000212345675605);
	printf("%.5g\n", 0.00021234565605);
	ft_printf("--------\n");
	ft_printf("%g\n", 0.000212345675605);
	printf("%g\n", 0.00021234565605);
	ft_printf("--------\n");
	ft_printf("%.1g\n", 0.000212345675605);
	printf("%.1g\n", 0.00021234565605);
	ft_printf("--------\n");
	ft_printf("%.0g\n", 0.000212345675605);
	printf("%.0g\n", 0.00021234565605);
	ft_printf("--------\n");
	ft_printf("%.0g\n", 0.00000212345675605);
	printf("%.0g\n", 0.0000021234565605);
	ft_printf("--------\n");
	ft_printf("%.0g\n", 2123456.75605);
	printf("%.0g\n", 2123456.75605);
	ft_printf("--------\n");
	ft_printf("%g\n", INFINITY);
	printf("%g\n", INFINITY);
	ft_printf("--------\n");
	ft_printf("%g\n", -INFINITY);
	printf("%g\n", -INFINITY);
	ft_printf("--------\n");
	ft_printf("%g\n", NAN);
	printf("%g\n", NAN);
	ft_printf("--------\n");
	ft_printf("%a\n", 43.3);
	printf("%a\n", 43.3);
	ft_printf("--------\n");
	ft_printf("%.100a\n", 43.3);
	printf("%.100a\n", 43.3);
	ft_printf("--------\n");
	ft_printf("%a\n", 16.16);
	printf("%a\n", 16.16);
	ft_printf("--------\n");
	ft_printf("%a\n", 5.23);
	printf("%a\n", 5.23);
	ft_printf("--------\n");
	ft_printf("%a\n", 2.3);
	printf("%a\n", 2.3);
	ft_printf("--------\n");
	ft_printf("%a\n", 25.12);
	printf("%a\n", 25.12);
	ft_printf("--------\n");
	ft_printf("%a\n", 25.12);
	printf("%a\n", 25.12);
	ft_printf("--------\n");
	ft_printf("%a\n", 25.12312132);
	printf("%a\n", 25.12312132);
	ft_printf("--------\n");
	ft_printf("%a\n", -25.12);
	printf("%a\n", -25.12);
	ft_printf("--------\n");
	ft_printf("%a\n", 43.3);
	printf("%a\n", 43.3);
	ft_printf("--------\n");
	ft_printf("%.100A\n", 43.3);
	printf("%.100A\n", 43.3);
	ft_printf("--------\n");
	ft_printf("%A\n", 16.16);
	printf("%A\n", 16.16);
	ft_printf("--------\n");
	ft_printf("%A\n", 5.23);
	printf("%A\n", 5.23);
	ft_printf("--------\n");
	ft_printf("%A\n", 0.5);
	printf("%A\n", 0.5);
	ft_printf("--------\n");
	ft_printf("%A\n", -0.5);
	printf("%A\n", -0.5);
	ft_printf("--------\n");
	ft_printf("%A\n", 12.5);
	printf("%A\n", 12.5);
	ft_printf("--------\n");
	ft_printf("%A\n", 122.5);
	printf("%A\n", 122.5);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.1);
	printf("%a\n", 0.1);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.2);
	printf("%a\n", 0.2);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.3);
	printf("%a\n", 0.3);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.4);
	printf("%a\n", 0.4);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.5);
	printf("%a\n", 0.5);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.6);
	printf("%a\n", 0.6);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.7);
	printf("%a\n", 0.7);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.8);
	printf("%a\n", 0.8);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.9);
	printf("%a\n", 0.9);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.02);
	printf("%a\n", 0.02);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.25);
	printf("%a\n", 0.25);
	ft_printf("--------\n");
	ft_printf("%a\n", 0.75);
	printf("%a\n", 0.75);
	ft_printf("--------\n");
	char str[100];
	char str2[100];
	for (v = -1.0; v <= 1.0; v += 0.0001)
	{
		sprintf(str, "%a\n", v);
		ft_sprintf(str2, "%a\n", v);
		if (ft_strcmp(str, str2) != 0)
		{
			ft_printf("%f", v);
			ft_printf("mistakes were made");
		}
	}
	ft_printf("done %C\n", L'👍');
	ft_printf("--------\n");
	ft_printf("%.3LF\n", 0.333333333333333333L);
	printf("%.3LF\n", 0.333333333333333333L);
	ft_printf("--------\n");
	ft_printf("%Lf\n", 0.333333333333333333L);
	printf("%Lf\n", 0.333333333333333333L);
	ft_printf("--------\n");
	ft_printf("%Le\n", 0.000000030L);
	printf("%Le\n", 0.0000003L);
	return (0);
}
