/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:49:26 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/16 18:54:42 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>
#include <locale.h>

int		main()
{
	setlocale(LC_ALL, "");
	ft_printf("%C\n", 720);
	printf("%C\n", 720);
	return (0);
}

//3073
