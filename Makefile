# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 17:34:45 by rbalbous          #+#    #+#              #
#    Updated: 2017/12/13 15:37:47 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Ofast

SRCS =	ft_printf.c \
		add.c \
		ft_parse.c \
		ft_error.c \
		pf_hashtag.c \
		ft_minus.c \
		ft_plus.c \
		ft_preci.c \
		pf_fwidth.c \
		ft_space.c \
		ft_zero.c \
		pf_percent.c \
		pf_empty.c \
		pf_s.c \
		pf_c.c \
		pf_d.c \
		pf_cap_d.c \
		pf_hd.c \
		pf_hhd.c \
		pf_lld.c \
		pf_zd.c \
		pf_jd.c \
		pf_u.c \
		pf_cap_u.c \
		pf_hhu.c \
		pf_hu.c \
		pf_llu.c \
		pf_ju.c \
		pf_zu.c \
		pf_o.c \
		pf_hho.c \
		pf_ho.c \
		pf_cap_o.c \
		pf_llo.c \
		pf_jo.c \
		pf_zo.c \
		pf_x.c \
		pf_cap_x.c \
		pf_llx.c \
		pf_lx.c \
		pf_hx.c \
		pf_hhx.c \
		pf_jx.c \
		pf_zx.c \
		addwp.c \
		pf_itoa.c \
		pf_uitoa.c \
		pf_uitoa_hexa.c \
		ft_j.c \
		pf_l.c \
		pf_h.c \
		pf_z.c

SRCSLIB = 	ft_strcat.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
			ft_strncat.c ft_strncpy.c ft_tolower.c ft_toupper.c \
			ft_bzero.c ft_atoi.c ft_strcmp.c ft_strchr.c ft_strrchr.c \
			ft_strstr.c ft_strnstr.c ft_strnew.c ft_strdel.c ft_strclr.c \
			ft_strequ.c ft_strnequ.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c \
			ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memdel.c \
			ft_memalloc.c ft_putchar.c ft_putnbr.c ft_putstr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_strjoin.c ft_strtrim.c ft_memmove.c \
			ft_strncmp.c ft_memcmp.c ft_strsub.c ft_strsplit.c ft_striter.c \
			ft_striteri.c ft_strmap.c ft_strmapi.c ft_itoa.c ft_lstmap.c \
			ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c \
			ft_lstaddlast.c ft_strjoinfree.c ft_max.c ft_min.c ft_memacpy.c \
			ft_sort_int.c ft_puterror.c ft_countwords.c ft_putitab.c \
			ft_putstab.c ft_tablen.c ft_intlen.c ft_strsplitfree.c
		
SRC = $(addprefix srcs/, $(SRCS))
SRCLIB = $(addprefix $(LIBFT_PATH)/, $(SRCSLIB))

OBJ = $(SRC:.c=.o) $(SRCLIB:.c=.o)

INCLUDES = includes

LIBFT_PATH = srcs/libft
LIBFT = $(addprefix $(LIBFT_PATH)/, libft.a)

all : $(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $^
			ranlib $(NAME)

%.o :		%.c $(INCLUDES)/ft_printf.h
			$(CC) -o $@ -c $< -I $(LIBFT_PATH) -I $(INCLUDES) $(CFLAGS)
			
clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)
		
re :		fclean all

.PHONY: all clean fclean re
