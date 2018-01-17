/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:33:33 by exam              #+#    #+#             */
/*   Updated: 2018/01/14 22:59:25 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t i;
	size_t a;
	unsigned char const *ptr = addr;

	i = 0;
	while (i < size)
	{
		a = 0;
		while (a < 16 && a + i < size)
		{
			ft_putnbr_hex(*(ptr + i + a), 2);
			if (a % 2)
				write(1, " ", 1);
			a++;
		}
		a = 0;
		write(1, "\n", 1);
		i += 16;
	}
}
