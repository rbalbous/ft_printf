/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:49:26 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/28 18:56:01 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int		main()
{
	char	*i = "afreis";

	ft_printf("%-#12.15hs", 12, i);
	return (0);
}
