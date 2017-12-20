/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/20 22:05:02 by rbalbous         ###   ########.fr       */
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
	double z = 0;

	setlocale(LC_ALL, "");
	i = ft_printf("{%+-#7.2f}\n", 2.9999999);
	j = printf("{%+-#7.2f}\n", 2.9999999);
	ft_printf("%d %d\n", i, j);
	i = ft_printf("{%#7.2f}\n", 2.9999999);
	j = printf("{%#7.2f}\n", 2.9999999);
	ft_printf("%d %d\n", i, j);
	i = ft_printf("{%+-#7.0f}\n", 2.9999999);
	j = printf("{%+-#7.0f}\n", 2.9999999);
	ft_printf("%d %d\n", i, j);
	i = ft_printf("{%+-#7.2f}\n", 2.);
	j = printf("{%+-#7.2f}\n", 2.);
	ft_printf("%d %d\n", i, j);
	i = ft_printf("{%.2f}\n", 2.);
	j = printf("{%.2f}\n", 2.);
	ft_printf("%d %d\n", i, j);
	i = ft_printf("{%.0f}\n", 2.);
	j = printf("{%.0f}\n", 2.);
	ft_printf("%d %d\n", i, j);
	i = ft_printf("{%07.2f}\n", 2.9999999);
	j = printf("{%07.2f}\n", 2.9999999);
	ft_printf("%d %d\n", i, j);
	i = ft_printf("%#+015f\n", z);
	j = printf("%#+015f\n", z);
	ft_printf("%d %d\n", i, j);
	return (0);
}
