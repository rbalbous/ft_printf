/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/29 17:35:55 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"

# define BUFF_SIZE 9999

typedef enum	e_length
{
			none,
			hh,
			h,
			ll,
			l,
			j,
			z,
}				t_len;

typedef struct	s_var
{
		int		index;
		int		bufindex;
		char	buf[BUFF_SIZE];
		int		len;
}				t_var;

typedef struct	s_flags
{
		int		minus : 1;
		int		plus : 1;
		int		hashtag : 1;
		int		space : 1;
		int		zero : 1;
		int		precision : 1;
		int		fwidth : 1;
		t_len	length;
}				t_flags;

int		ft_printf(const char *format, ...);
void	parse(const char *str, t_var *var, va_list ap);
void	addchar(const char c, t_var *var);
void	addstr(const char *str, size_t len, t_var *var);
void	create(char c, t_var *var, t_flags *flags);
int		ft_error(t_flags *flags, t_var *var, const char *format, va_list ap);
int		ft_hashtag(t_flags *flags, t_var *var, const char *format, va_list ap);
int		ft_minus(t_flags *flags, t_var *var, const char *format, va_list ap);
int		ft_plus(t_flags *flags, t_var *var, const char *format, va_list ap);
int		ft_preci(t_flags *flags, t_var *var, const char *format, va_list ap);
int		ft_space(t_flags *flags, t_var *var, const char *format, va_list ap);
int		ft_zero(t_flags *flags, t_var *var, const char *format, va_list ap);


#endif
