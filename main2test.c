/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:19:23 by rbalbous         ###   ########.fr       */
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
	int			n = 0;
	int			m = 0;
	struct tm	*tm;

	setlocale(LC_ALL, "");
 	//time(&ti);
	/*tm = localtime(&ti);
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
			ft_printf("%f", i);
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
	ft_sprintf(str, "[%e]\n", 1.000000);
	sprintf(str2, "[%e]\n", 1.000000);
	printf("%s%s", str, str2);
	ft_printf("[%15f]\n", 1.0);
	printf("[%15f]\n", 1.0);
	ft_printf("[%15.15g]\n", 1.0);
	printf("[%15.15g]\n", 1.0);
	ft_printf("[%15.15f]\n", 1.0);
	printf("[%15.15f]\n", 1.0);
	ft_printf("[%15.15f]\n", 1.1);
	printf("[%15.15f]\n", 1.1);
	ft_printf("[%+15.0f]\n", 1.1);
	printf("[%+15.0f]\n", 1.1);
	ft_printf("[%+15.5f]\n", 1.1);
	printf("[%+15.5f]\n", 1.1);
	ft_printf("[%+15.15f]\n", 1.1);
	printf("[%+15.15f]\n", 1.1);
	ft_printf("[%015.0g]\n", 42.42);
	printf("[%015.0g]\n", 42.42);
	ft_printf("[%g]\n", -243.376767676666);
	printf("[%g]\n", -243.376767676666);
	n = ft_printf("%s\n", "Hello World");
	m = printf("%s\n", "Hello World");
	ft_printf("%d\n", n);
	ft_printf("%d\n", m);
	n = ft_printf("[%3.2ls]\n", L"❤ coeur ሴ ☂" );
	m = printf("[%3.2ls]\n", L"❤ coeur ሴ ☂" );
	ft_printf("[%ls]\n", L"❤ coeur ሴ ☂" );
	printf("[%ls]\n", L"❤ coeur ሴ ☂" );
	ft_printf("[%3.5ls]\n", L"❤ coeur ሴ ☂" );
	printf("[%3.5ls]\n", L"❤ coeur ሴ ☂" );
	ft_printf("[%3ls]\n", L"❤ coeur ሴ ☂" );
	printf("[%3ls]\n", L"❤ coeur ሴ ☂" );
	ft_printf("[%25.5ls]\n", L"❤ coeur ሴ ☂" );
	printf("[%25.5ls]\n", L"❤ coeur ሴ ☂" );
	int		r;
	r = ft_printf("%ls\n", L"❤" );
	m = printf("[%25.5ls]\n", L"❤" );
	ft_printf("LA%d\n", r);
	ft_printf("%d\n", m);
	n = ft_printf("[test %s %C]", "bla", 0xd800);
	m = printf("[test %s %C]", "bla", 0xd800);
	ft_printf("%d\n", n);
	ft_printf("%d\n", m);
	n = ft_printf("[test0123456789]\n");
	m = printf("[test0123456789]\n");
	ft_printf("%d\n", n);
	ft_printf("%d\n", m);
	ft_printf("[%0.0e]\n", 0.0);
	printf("[%0.0e]\n", 0.0);
	ft_printf("%#0-3.15e\n", 42.402);
	printf("%#0-3.15e\n", 42.402);
	int tabl[3];
    tabl[0] = 0x1234;
    tabl[1] = 0x1234;
    tabl[2] = 0x1234;
    ft_printf("%S\n", tabl);
    printf("%S\n", tabl);*/
	int k;
   /* k = ft_printf("%5.0s", 42);
	ft_printf("%d\n", k);
	ft_printf("{%15.20e}\n", 654321.123456);
	printf("{%15.20e}\n", 654321.123456);
	v = 0;
	k = ft_printf("%3.0g\n", v);
	ft_printf("%d\n", k);
	k = printf("%3.0g\n", v);
	ft_printf("%d\n", k);
	wchar_t *str;

	str = NULL;
	k = ft_printf("[%3.2S]\n", str);
	printf("[%3.2S]\n", str);
	str = L"Hello World";
	k = ft_printf("[%3.2S]\n", str);
	printf("[%3.2S]\n", str);
	k = ft_printf("{%21a}\n", 43.3);
	ft_printf("%d\n", k);
	k = printf("{%21a}\n", 43.3);
	ft_printf("%d\n", k);
	ft_printf("{%0-4.s}\n", 42);
	printf("{%0-4.s}\n", 42);
	ft_printf("{%*s}\n", 5, 0);
	printf("{%*s}\n", 5, 0);
	ft_printf("{%25.30S}\n", NULL);
	printf("{%25.30S}\n", NULL);
	ft_printf("{%3.2S}\n", NULL);
	printf("{%3.2S}\n", NULL);
	v = 0;
	ft_printf("{%15f}\n", v);
	printf("{%15f}\n", v);
	ft_printf("{%-+15.5f}\n", v);
	printf("{%-+15.5f}\n", v);
	ft_printf("{%3.0f}\n", v);
	printf("{%3.0f}\n", v);
	ft_printf("{%+3.0f}\n", v);
	printf("{%+3.0f}\n", v);
	ft_printf("%15a\n", 0);
	printf("%15a\n", 0);
	ft_printf("%#0+15f\n", 0);
	printf("%#0+15f\n", 0);
	ft_printf("%#0+15.5f\n", 0);
	printf("%#0+15.5f\n", 0);
	ft_printf("%3.2f\n", 1.425315487);
	printf("%3.2f\n", 1.425315487);
	v = 4255;
	ft_printf("{%3.0f}\n", v);
	printf("{%3.0f}\n", v);
	v = 42.42;
	ft_printf("{%3.0f}\n", v);
	printf("{%3.0f}\n", v);
	ft_printf("{%15f}\n", v);
	printf("{%15f}\n", v);
	ft_printf("{%15f}\n", v);
	printf("{%15f}\n", v);
	v = -243.376767676666;
	ft_printf("{%015f}\n", v);
	printf("{%015f}\n", v);
	v = 0;
	ft_printf("{%3.0e}\n", v);
	printf("{%3.0e}\n", v);
	ft_printf("{%15e}\n", v);
	printf("{%15e}\n", v);
	ft_printf("{%Le}\n", 42.42L);
	printf("{%Le}\n", 42.42L);
	ft_printf("{%3Le}\n", 42.42L);
	printf("{%3Le}\n", 42.42L);
	ft_printf("{%3.0Le}\n", 42.42L);
	printf("{%3.0Le}\n", 42.42L);
	ft_printf("{%3.2Le}\n", 42.42L);
	printf("{%3.2Le}\n", 42.42L);
	ft_printf("{%0Le}\n", 42.42L);
	printf("{%0Le}\n", 42.42L);
	ft_printf("{%.0Le}\n", 42.42L);
	printf("{%.0Le}\n", 42.42L);
	ft_printf("{%3.2Le}\n", 42.42L);
	printf("{%3.2Le}\n", 42.42L);*/
	v = 0;
	/*ft_printf("%#g\n", v);
	printf("%#g\n", v);
	ft_printf("%g\n", v);
	printf("%g\n", v);
	ft_printf("[%3.2g]\n", v);
	printf("[%3.2g]\n", v);
	ft_printf("[%2.1g]\n", v);
	printf("[%2.1g]\n", v);
	ft_printf("[%#3.0g]\n", v);
	printf("[%#3.0g]\n", v);
	ft_printf("[%#3.2g]\n", v);
	printf("[%#3.2g]\n", v);
	ft_printf("[%3g]\n", 1.42532);
	printf("[%3g]\n", 1.42532);
	ft_printf("[%9g]\n", 1.42532);
	printf("[%9g]\n", 1.42532);
	ft_printf("[% 3.0g]\n", 1.42532);
	printf("[% 3.0g]\n", 1.42532);
	ft_printf("[%3.0g]\n", 1.42532);
	printf("[%3.0g]\n", 1.42532);
	ft_printf("[%19.10g]\n", 42.42);
	printf("[%19.10g]\n", 42.42);
	ft_printf("[%a]\n", 42.42);
	printf("[%a]\n", 42.42);
	ft_printf("[%25.10a]\n", 42.42);
	printf("[%25.10a]\n", 42.42);
	ft_printf("[%a]\n", 42.42);
	printf("[%a]\n", 42.42);
	ft_printf("[%.0a]\n", 42.42);
	printf("[%.0a]\n", 42.42);
	ft_printf("[%25.10a]\n", 42.42);
	printf("[%25.10a]\n", 42.42);
	ft_printf("[%25.6a]\n", 42.42);
	printf("[%25.6a]\n", 42.42);
	ft_printf("[%25.12a]\n", 42.44);
	printf("[%25.12a]\n", 42.44);
	ft_printf("[%+25.6a]\n", 42.42);
	printf("[%+25.6a]\n", 42.42);
	ft_printf("Coucou %.0s\n%s%---12s", "hi", "coco", NULL);
	ft_printf("\n");
	printf("Coucou %.0s\n%s%---12s", "hi", "coco", NULL);
	wchar_t	s[4];
	s[0] = 0x53;
	s[1] = 0xd800;
	s[2] = 0x81000;
	s[3] = '\0';
	n = ft_printf("%S\n", s);
	printf("%S\n", s);
	ft_printf("%d", n);
	ft_printf("%La\n", 0.L);*/
	/*v = 0;
	ft_printf("[%#25.0a]\n", v);
	printf("[%#25.0a]\n", v);
	ft_printf("[%025.0a]\n", v);
	printf("[%025.0a]\n", v);
	ft_printf("[%-025.0a]\n", v);
	printf("[%-025.0a]\n", v);
	ft_printf("[%25.0La]\n", 0.L);
	printf("[%25.0La]\n", 0.L);
	ft_printf("[%3.2La]\n", 0.L);
	printf("[%3.2La]\n", 0.L);
	ft_printf("[%15.5La]\n", 0.L);
	printf("[%15.5La]\n", 0.L);
	ft_printf("[%15La]\n", 0.L);
	printf("[%15La]\n", 0.L);
	ft_printf("[%+025.0a]\n", v);
	printf("[%+025.0a]\n", v);
	ft_printf("[%15.0a]\n", 0.000000005);
	printf("[%15.0a]\n", 0.000000005);
	ft_printf("[%15La]\n", 654321.123456L);
	printf("[%15La]\n", 654321.123456L);
	ft_printf("[%15a]\n", -654321.123456);
	printf("[%15a]\n", -654321.123456);
	ft_printf("[%15La]\n", -654321.123456L);
	printf("[%15La]\n", -654321.123456L);
	ft_printf("[%15.0La]\n", -654321.123456L);
	printf("[%15.0La]\n", -654321.123456L);
	ft_printf("[%.a]\n", 1.9);
	printf("[%.a]\n", 1.9);
	ft_printf("[%15LA]\n", 654321.123456L);
	printf("[%15LA]\n", 654321.123456L);
	v = 0;
	ft_printf("[%15.0e]\n", v);
	printf("[%15.0e]\n", v);
	ft_printf("[%#15.0e]\n", v);
	printf("[%#15.0e]\n", v);
	ft_printf("[%#0+15.0e]\n", v);
	printf("[%#0+15.0e]\n", v);
	ft_printf("[%+15e]\n", -101.101);
	printf("[%+15e]\n", -101.101);
	ft_printf("[%15.0Le]\n", 0.L);
	printf("[%15.0Le]\n", 0.L);
	ft_printf("[%e]\n", 1.425315487);
	printf("[%e]\n", 1.425315487);
	ft_printf("[%15.15Le]\n", 8008.2L);
	printf("[%15.15Le]\n", 8008.2L);
	ft_printf("[%15.18Le]\n", 8008.2L);
	printf("[%15.18Le]\n", 8008.2L);
	ft_printf("[%3.0e]\n", 8008.2);
	printf("[%3.0e]\n", 8008.2);
	ft_printf("[%3.0e]\n",	42.42);
	printf("[%3.0e]\n", 42.42);
	ft_printf("[%3.2e]\n",	42.42);
	printf("[%3.2e]\n", 42.42);
	ft_printf("[%3e]\n", 42.42);
	printf("[%3e]\n", 42.42);
	ft_printf("%15.0e\n", 654321.123456);
	printf("%15.0e\n", 654321.123456);
	ft_printf("[%#3.0e]\n", v);
	printf("[%#3.0e]\n", v);
	ft_printf("[% a]\n", 1703.0541684);
	printf("[% a]\n", 1703.0541684);
	ft_printf("[%a]\n", 0.);
	printf("[%a]\n", 0.);
	ft_printf("[%.0a]\n", 1703.0541684);
	printf("[%.0a]\n", 1703.0541684);
	ft_printf("[%3.2g]\n", 1.425315487);
	printf("[%3.2g]\n", 1.425315487);
	ft_printf("[%3.0g]\n", 1.425315487);
	printf("[%3.0g]\n", 1.425315487);
	ft_printf("[%15.13g]\n", 1.425315487);
	printf("[%15.13g]\n", 1.425315487);
	ft_printf("[%#3.0g]\n", 1.425315487);
	printf("[%#3.0g]\n", 1.425315487);
	ft_printf("[%#3.0a]\n", 0.);
	printf("[%#3.0a]\n", 0.);
	ft_printf("[%3.0a]\n", 0.);
	printf("[%3.0a]\n", 0.);
	ft_printf("[%#.0a]\n", 1703.0541684);
	printf("[%#.0a]\n", 1703.0541684);
	ft_printf("[%#a]\n", 0.);
	printf("[%#a]\n", 0.);
	ft_printf("[%3.0La]\n", 654321.123456L);
	printf("[%3.0La]\n", 654321.123456L);
	ft_printf("[%La]\n", 654321.123456L);
	printf("[%La]\n", 654321.123456L);
	ft_printf("[%3.0La]\n", -42.402L);
	printf("[%3.0La]\n", -42.402L);
	ft_printf("[%#3.0La]\n", 654321.123456L);
	printf("[%#3.0La]\n", 654321.123456L);
	ft_printf("[%3.0a]\n", 50000.0);
	printf("[%3.0a]\n", 50000.0);
	ft_printf("[%#3.0a]\n", 50000.0);
	printf("[%#3.0a]\n", 50000.0);
	ft_printf("[%#a]\n", 1.);
	printf("[%#a]\n", 1.);
	ft_printf("[%#a]\n", 42.);
	printf("[%#a]\n", 42.);
	ft_printf("%0 3.5a\n", 54321.12345);
	printf("%0 3.5a\n", 54321.12345);
	ft_printf("[%#3.0LA]\n", 654321.123456L);
	printf("[%#3.0LA]\n", 654321.123456L);
	ft_printf("[%3.0A]\n", 50000.0);
	printf("[%3.0A]\n", 50000.0);
	ft_printf("[%#3.0A]\n", 50000.0);
	printf("[%#3.0A]\n", 50000.0);
	ft_printf("[%#A]\n", 1.);
	printf("[%#A]\n", 1.);
	ft_printf("[%#A]\n", 42.);
	printf("[%#A]\n", 42.);
	ft_printf("%0 3.5A\n", 54321.12345);
	printf("%0 3.5A\n", 54321.12345);
	n = ft_printf("%A\n", 0.0);
	m = printf("%A\n", 0.0);
	ft_printf("[%#3.0LA]\n", -42.42L);
	printf("[%#3.0LA]\n", -42.42L);
	ft_printf("[%LA]\n", 654321.123456L);
	printf("[%#LA]\n", 654321.123456L);
	ft_printf("[%A]\n", NAN);
	printf("[%#A]\n", NAN);
	ft_printf("[%a]\n", NAN);
	printf("[%#a]\n", NAN);
	ft_printf("[%+-12.8F]\n", INFINITY);
	printf("[%+-12.8F]\n", INFINITY);
	ft_printf("[%+-12f]\n", INFINITY);
	printf("[%+-12f]\n", INFINITY);
	ft_printf("%g\n", -0.00000045365897452);
	printf("%g\n", -0.00000045365897452);
	ft_printf("%g\n", 0.00000045365897452);
	printf("%g\n", 0.00000045365897452);
	ft_printf("%.0g\n", -0.00000045365897452);
	printf("%.0g\n", -0.00000045365897452);
	ft_printf("%#.0g\n", 0.00000045365897452);
	printf("%#.0g\n", 0.00000045365897452);
	ft_printf("[%15.0g]\n", -0.00000045365897452);
	printf("[%15.0g]\n", -0.00000045365897452);
	ft_printf("[%#15.4g]\n", 0.000000);
	printf("[%#15.4g]\n", 0.000000);
	ft_printf("%g\n", 4.5365897452);
	printf("%g\n", 4.5365897452);
	ft_printf("[%3.0g]\n", 0.000000);
	printf("[%3.0g]\n", 0.000000);
	ft_printf("[%3.0g]\n", 1.425315487);
	printf("[%3.0g]\n", 1.425315487);
	ft_printf("[%#3.0g]\n", 1.425315487);
	printf("[%#3.0g]\n", 1.425315487);
	ft_printf("[%3g]\n", 0.0);
	printf("[%3g]\n", 0.0);
	ft_printf("[%#3.15g]\n", 1.42531548700000);
	printf("[%#3.15g]\n", 1.425315487000000);
	ft_printf("[%3.0g]\n", 5.000);
	printf("[%3.0g]\n", 5.000);
	ft_printf("[%#3.15g]\n", 0.000000005);
	printf("[%#3.15g]\n", 0.000000005);
	ft_printf("[%#3.0g]\n", 42.42);
	printf("[%#3.0g]\n", 42.42);
	ft_printf("[%g]\n", 42.42);
	printf("[%g]\n", 42.42);
	ft_printf("[%#g]\n", 42.42);
	printf("[%#g]\n", 42.42);
	ft_printf("[%g]\n", 4242.42);
	printf("[%g]\n", 4242.42);
	ft_printf("[%g]\n", 42424.4);
	printf("[%g]\n", 42424.4);
	ft_printf("[%g]\n", 42424.44);
	printf("[%g]\n", 42424.44);
	ft_printf("[%g]\n", 424242.44);
	printf("[%g]\n", 424242.44);
	ft_printf("[%g]\n", 4242424.44);
	printf("[%g]\n", 4242424.44);
	ft_printf("[%#3.0g]\n", 42.42);
	printf("[%#3.0g]\n", 42.42);
	ft_printf("[%3.2g]\n", 42.42);
	printf("[%3.2g]\n", 42.42);
	ft_printf("[%#3.2g]\n", 42.42);
	printf("[%#3.2g]\n", 42.42);
	ft_printf("[%15.0g]\n", 42.42);
	printf("[%15.0g]\n", 42.42);
	ft_printf("[%#3.0g]\n", 1.425315487);
	printf("[%#3.0g]\n", 1.425315487);
	ft_printf("[%15g]\n", -0.0000000000000000000000000005);
	printf("[%15g]\n", -0.0000000000000000000000000005);
	ft_printf("[%#03.2g]\n", 101.101);
	printf("[%#03.2g]\n", 101.101);
	ft_printf("[%3.5g]\n", 50000.0);
	printf("[%3.5g]\n", 50000.0);
	ft_printf("[%#0-15.0g]\n", -243.376767676666);
	printf("[%#0-15.0g]\n", -243.376767676666);
	ft_printf("[%0g]\n", 101.101);
	printf("[%0g]\n", 101.101);
	ft_printf("[%0g]\n", 8008.2);
	printf("[%0g]\n", 8008.2);
	ft_printf("[%3.2g]\n", 1.01);
	printf("[%3.2g]\n", 1.01);
	ft_printf("[%3.2f]\n", 1.01);
	printf("[%3.2f]\n", 1.01);
	ft_printf("[%3.5g]\n", 1.01);
	printf("[%3.5g]\n", 1.01);
	ft_printf("[%g]\n", 50000.0);
	printf("[%g]\n", 50000.0);
	ft_printf("[%3.2LG]\n", -42.402L);
	printf("[%3.2LG]\n", -42.402L);
	ft_printf("[%'g]\n", 5.0);
	printf("[%'g]\n", 5.0);
	ft_printf("[%'g]\n", 50.0);
	printf("[%'g]\n", 50.0);
	ft_printf("[%'g]\n", 500.0);
	printf("[%'g]\n", 500.0);
	ft_printf("[%'g]\n", 5000.0);
	printf("[%'g]\n", 5000.0);
	ft_printf("[%'g]\n", 50000.0);
	printf("[%'g]\n", 50000.0);
	ft_printf("[%'15g]\n", 500000.0);
	printf("[%'15g]\n", 500000.0);
	ft_printf("[%'15g]\n", 8008.2);
	printf("[%'15g]\n", 8008.2);
	ft_printf("%9$d %1$f %2$d %3$d %4$d %5$d %6$d %7$d %8$d %10$d %11$d\n", 42.42, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
	printf("%9$d %1$f %2$d %3$d %4$d %5$d %6$d %7$d %8$d %10$d %11$d\n", 42.42, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);*/
	ft_printf("%15F\n", 0.0);
	printf("%15F\n", 0.0);
	return (0);
}
