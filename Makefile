# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 17:34:45 by rbalbous          #+#    #+#              #
#    Updated: 2017/12/02 17:34:44 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	ft_printf.c \
		add.c \
		ft_parse.c \
		ft_error.c \
		ft_hashtag.c \
		ft_minus.c \
		ft_plus.c \
		ft_preci.c \
		ft_space.c \
		ft_zero.c \
		percent.c \
		ft_s.c \
		ft_c.c \
		addwp.c
		
SRC = $(addprefix srcs/, $(SRCS))

OBJ = $(SRC:.c=.o)

INCLUDES = includes


all : $(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $^
			ranlib $(NAME)

%.o :		%.c $(INCLUDES)/ft_printf.h
			$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)
			
clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)
		
re :		fclean all

.PHONY: all clean fclean re
