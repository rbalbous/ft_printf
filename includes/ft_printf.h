/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/18 19:15:22 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
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

typedef enum	e_conv
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_conv;

typedef struct	s_var
{
	int			index;
	int			bufindex;
	char		buf[BUFF_SIZE];
}				t_var;

typedef struct	s_flags
{
	t_uint8		minus : 1;
	t_uint8		plus : 1;
	t_uint8		hashtag : 1;
	t_uint8		space : 1;
	t_uint8		zero : 1;
	t_uint8		isp : 1;
	t_uint8		isw : 1;
	t_int32		precision;
	t_int32		fwidth;
	t_uint8		capx : 1;
	char		cast;
	int			len;
	t_conv		conv;
}				t_flags;

int				ft_printf(const char *str, ...);
int				parse(unsigned char *str, t_var *var, va_list *ap
				, int (*f[256])());

void			addchar(const char c, t_var *var);
void			addnstr(void *str, size_t len, t_var *var);
void			addstr(char *str, t_var *var);
int				addnull(t_var *var);
int				addmchar(char c, t_var *var, int len);
int				addwp(t_flags *flags, t_var *var, char n);
int				wandp(t_flags *flags, t_var *var);

int				pf_hashtag(t_flags *flags);
int				ft_minus(t_flags *flags);
int				ft_plus(t_flags *flags);
int				ft_preci(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_fwidth(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				ft_space(t_flags *flags);
int				ft_zero(t_flags *flags);
int				pf_wildcard(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);

int				pf_s(t_flags *flags, t_var *var, va_list *ap);
int				pf_cap_s(t_flags *flags, t_var *var, va_list *ap);

int				len_one(wint_t c, t_var *var);
int				len_two(wint_t c, t_var *var);
int				len_three(wint_t c, t_var *var);
int				len_four(wint_t c, t_var *var);

int				pf_c(t_flags *flags, t_var *var, va_list *ap);
int				pf_cap_c(t_flags *flags, t_var *var, va_list *ap);

int				pf_d(t_flags *flags, t_var *var, va_list *ap);
int				pf_spe_d(t_flags *flags, t_var *var, va_list *ap);
int				pf_cap_d(t_flags *flags, t_var *var, va_list *ap);
int				pf_hd(t_flags *flags, t_var *var, va_list *ap);
int				pf_hhd(t_flags *flags, t_var *var, va_list *ap);
int				pf_lld(t_flags *flags, t_var *var, va_list *ap);
int				pf_jd(t_flags *flags, t_var *var, va_list *ap);
int				pf_zd(t_flags *flags, t_var *var, va_list *ap);

int				pf_u(t_flags *flags, t_var *var, va_list *ap);
int				pf_spe_u(t_flags *flags, t_var *var, va_list *ap);
int				pf_cap_u(t_flags *flags, t_var *var, va_list *ap);
int				pf_hhu(t_flags *flags, t_var *var, va_list *ap);
int				pf_hu(t_flags *flags, t_var *var, va_list *ap);
int				pf_llu(t_flags *flags, t_var *var, va_list *ap);
int				pf_ju(t_flags *flags, t_var *var, va_list *ap);
int				pf_zu(t_flags *flags, t_var *var, va_list *ap);

int				pf_o(t_flags *flags, t_var *var, va_list *ap);
int				pf_spe_o(t_flags *flags, t_var *var, va_list *ap);
int				pf_hho(t_flags *flags, t_var *var, va_list *ap);
int				pf_ho(t_flags *flags, t_var *var, va_list *ap);
int				pf_cap_o(t_flags *flags, t_var *var, va_list *ap);
int				pf_llo(t_flags *flags, t_var *var, va_list *ap);
int				pf_jo(t_flags *flags, t_var *var, va_list *ap);
int				pf_zo(t_flags *flags, t_var *var, va_list *ap);

int				pf_x(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_sp_x(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_lx(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_llx(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_hx(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_hhx(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_jx(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_zx(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_cap_x(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);

int				pf_percent(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				pf_empty_d(t_flags *flags, t_var *var);
int				pf_empty_o(t_flags *flags, t_var *var);
int				pf_empty_u(t_flags *flags, t_var *var);
int				pf_empty_x(t_flags *flags, t_var *var, unsigned char *str);
int				pf_empty_s(t_flags *flags, t_var *var);

int				pf_l(t_flags *flags, t_var *var, va_list *ap
				, unsigned char *str);
int				ft_j(t_flags *flags);
int				pf_h(t_flags *flags);
int				pf_z(t_flags *flags);

void			pf_itoa(intmax_t n, t_flags *flags, t_var *var);
size_t			pf_intlen(intmax_t n, int base);

size_t			pf_uintlen(uintmax_t n, int base);
void			pf_uitoa_base(uintmax_t n, int base, t_flags *flags
				, t_var *var);

void			pf_uitoa_hexa(uintmax_t n, t_flags *flags, t_var *var);

#endif
