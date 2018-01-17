/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/17 19:13:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <time.h>
#include <limits.h>
#include <locale.h>
#include <langinfo.h>
#include <nl_types.h>
#include <stdlib.h>

int		main(void)
{
	double v = -1.0;
	long double w = -1.0L;
	time_t		ti =   983768949;
	time_t		tw =   1509286422;
	time_t		te =   1509372822;
	struct tm	*tm;

	setlocale(LC_ALL, "");
 	//time(&ti);
	tm = localtime(&ti);
	ft_printf("%s", ctime(&ti));
	ft_printf ("%k\n", tm);
	tm = localtime(&te);
	ft_printf("%s", ctime(&te));
	ft_printf ("%k\n", tm);
	tm = localtime(&tw);
	ft_printf("%s", ctime(&tw));
	ft_printf ("%k\n", tm);
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
	double		i;
	char		lourd[15];
	char		lour[15];

	i = 1;
	while (i < 1000)
	{
		ft_sprintf(lourd, "%g", 1 / (i * i * i * i));
		sprintf(lour, "%g", 1 / (i * i * i * i));
		if (ft_strcmp(lourd, lour) != 0)
		{
			ft_printf("%f ", i);
			ft_printf("mistakes were made %s %s\n", lourd, lour);
		}
		i++;
	}
	ft_printf("done %C\n", L'👍');
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
		ft_sprintf(str, "[%e]", v);
		sprintf(str2, "[%e]", v);
		if (ft_strcmp(str, str2) != 0)
		{
			ft_printf("%f\n%s %s\n", v, str, str2);
			ft_printf("mistakes were made");
		}
	}
	ft_printf("done %C\n", L'👍');
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
	for (w = -1.0L; w <= 1.0L; w += 0.0001L)
	{
		sprintf(str, "%La\n", w);
		ft_sprintf(str2, "%La\n", w);
		if (ft_strcmp(str, str2) != 0)
		{
			ft_printf("%Lf %s %s", w, str, str2);
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
	ft_printf("%Le\n", 0.0000003L);
	printf("%Le\n", 0.0000003L);
	ft_printf("--------\n");
	ft_printf("%r\n", "legen\0dary");
	ft_printf("%.15r\n", "legen\0dary");
	ft_printf("%3$c %1$s %5$d %4$c %2$s\n", "dd", "eee", 'm', 'd', 1234);
	printf("%3$c %1$s %5$d %4$c %2$s\n", "dd", "eee", 'm', 'd', 1234);
	ft_printf("%3$c %1$s %4$x %2$s\n", "dd", "eee", 'm', 123);
	printf("%3$c %1$s %4$x %2$s\n", "dd", "eee", 'm', 123);
	ft_printf("%5$25ld %1$29llu %9$ld\n", ULONG_LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX , LONG_MAX);
	printf("%5$25ld %1$29llu %9$ld\n", ULONG_LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX , LONG_MAX);
	ft_printf("%3$s %1$s %2$s\n", "seb", "le", "naze");
	printf("%3$s %1$s %2$s\n", "seb", "le", "naze");
	ft_printf("%1$s %3$x %2$s\n", "dd", "eee", 123);
	printf("%1$s %3$x %2$s\n", "dd", "eee", 123);
	ft_printf("%3$c %1$s %4$d %2$s\n", "dd", "eee", 'm', 1234);
	printf("%3$c %1$s %4$d %2$s\n", "dd", "eee", 'm', 1234);
	ft_printf("%3$c %1$s %4$d %2$s %7$c %5$s %8$d %6$s\n", "dd", "eee", 'm', 1234, "dd", "eee", 'm', 1234);
	printf("%3$c %1$s %4$d %2$s %7$c %5$s %8$d %6$s\n", "dd", "eee", 'm', 1234, "dd", "eee", 'm', 1234);
	ft_printf("%3$c %1$s %4$llu %2$s %7$c %5$s %8$llu %6$s\n", "dd", "eee", 'm', 12345644566456456645, "dd", "eee", 'm', 12345644566456456645);
	printf("%3$c %1$s %4$llu %2$s %7$c %5$s %8$llu %6$s\n", "dd", "eee", 'm', 12345644566456456645, "dd", "eee", 'm', 12345644566456456645); 
	char    *tab[10] = {"0", "23", "150", "255", "12", "16", "42", "103", "4242"};
	ft_printf("%0.1m\n", tab, sizeof(tab));
	ft_printf("%r\n", "\a");
	int f = 0;
	int g = 0;
	f = ft_printf("%6C et coco %C titi %C tyty\n", 3250, 0xd800, 'u');
	ft_printf("\n");
	g = printf("%6C et coco %C titi %C tyty\n", 3250, 0xd800, 'u');
	printf("\n");
	ft_printf("\n%d %d\n", f, g);
	ft_printf("%La\n", 16.16L);
	printf("%La\n", 16.16L);
	ft_printf("%La\n", 1.16L);
	printf("%La\n", 1.16L);
	ft_printf("%La\n", .116L);
	printf("%La\n", .116L);
	ft_printf("%La\n", 1.12L);
	printf("%La\n", 1.12L);
	ft_printf("%La\n", 0.00012L);
	printf("%La\n", 0.00012L);
	ft_printf("%La\n", 0.0012L);
	printf("%La\n", 0.0012L);
	ft_printf("%La\n", -0.000100L);
	printf("%La\n", -0.000100L);
	ft_printf("%LA\n", 16.16L);
	printf("%LA\n", 16.16L);
	ft_printf("%LA\n", 1.16L);
	printf("%LA\n", 1.16L);
	ft_printf("%LA\n", .116L);
	printf("%LA\n", .116L);
	ft_printf("%LA\n", 1.12L);
	printf("%LA\n", 1.12L);
	ft_printf("%LA\n", 0.00012L);
	printf("%LA\n", 0.00012L);
	ft_printf("%LA\n", 0.0012L);
	printf("%LA\n", 0.0012L);
	ft_printf("%LA\n", -0.000100L);
	printf("%LA\n", -0.000100L);
	ft_printf("%+3.0a\n", 101.101);
	printf("%+3.0a\n", 101.101);
	ft_printf("%.La\n", 1.000L);
	printf("%.La\n", 1.000L);
	double doub;
	doub = 999;
	ft_printf("%e\n", 1 / (doub * doub * doub * doub));
	printf("%e\n", 1 / (doub * doub * doub * doub));
	ft_printf("%g\n", 0.0075605);
	printf("%g\n", 0.0075605);
	ft_printf("%g\n", 1.000000);
	printf("%g\n", 1.000000);
	ft_printf("%.4g\n", 0.0075605);
	printf("%.4g\n", 0.0075605);
	ft_printf("%.4g\n", 1.000000);
	printf("%.4g\n", 1.000000);
	ft_printf("%.8g\n", 0.0075605);
	printf("%.8g\n", 0.0075605);
	ft_printf("%.14g\n", 0.0075605);
	printf("%.14g\n", 0.0075605);
	ft_printf("[%3.0f]\n", 0.0);
	printf("[%3.0f]\n", 0.0);
	ft_printf("[%3F]\n", 0.0);
	printf("[%3F]\n", 0.0);
	ft_printf("[%15.0f]\n", 0.0);
	printf("[%15.0f]\n", 0.0);
	ft_printf("%w\n", "antoine a lunettes");
	ft_printf("%W\n", "H^jVYdXeTe`\\^[[d[f");
	ft_printf("[%'g]\n", 0.0);
	printf("[%'g]\n", 0.0);
	ft_printf("[%a]\n", 0.0);
	printf("[%a]\n", 0.0);
	ft_printf("%.35f\n", 32113213213514684.326464);
	printf("%.35f\n", 32113213213514684.326464);
	ft_sprintf(str, "[%e]\n", 0.000100);
	sprintf(str2, "[%e]\n", 0.000100);
	printf("%s%s", str, str2);
	return (0);
}
