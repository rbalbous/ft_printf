/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/02 17:34:31 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"

# define BUFF_SIZE 4096

typedef unsigned char		t_uint8;
typedef unsigned short int	t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long int	t_uint64;
typedef char				t_int8;
typedef short int			t_int16;
typedef int					t_int32;
typedef long int			t_int64;

typedef struct	s_var
{
	int			index;
	int			bufindex;
	char		buf[BUFF_SIZE];
	int			len;
}				t_var;

typedef struct	s_flags
{
	t_uint8		minus : 1;
	t_uint8		plus : 1;
	t_uint8		hashtag : 1;
	t_uint8		space : 1;
	t_uint8		zero : 1;
	t_int32		precision;
	t_int32		fwidth;
}				t_flags;

int		ft_printf(const char *str, ...);
int		parse(const char *str, t_var *var, va_list *ap
		, int (*f[256])());
void	addchar(const char c, t_var *var);
void	addnstr(const char *str, size_t len, t_var *var);
void	addstr(const char *str, t_var *var);
int		ft_error();
int		ft_hashtag(t_flags *flags);
int		ft_minus(t_flags *flags);
int		ft_plus(t_flags *flags);
int		ft_preci(t_flags *flags, t_var *var, const char *str);
int		ft_space(t_flags *flags);
int		ft_zero(t_flags *flags);
int		ft_s(t_flags *flags, t_var *var, const char *str, va_list *ap);
int		ft_c(t_flags *flags, t_var *var, const char *str, va_list *ap);
int		percent(t_flags *flags, t_var *var, const char *str);
int		addwp(t_flags *flags, t_var *var);

#endif
