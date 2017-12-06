/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:49:26 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/06 20:42:32 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>

#define TEST "%05d\n", -42

int		main()
{
	char	i[] = "afoures";
	int		r_nb = 0;
	int		m_nb = 0;

	m_nb = ft_printf(TEST);
	r_nb = printf(TEST);
	printf("m_nb : %d\nr_nb : %d\n", m_nb, r_nb);
	return (0);
}
