# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 17:34:45 by rbalbous          #+#    #+#              #
#    Updated: 2017/12/17 15:28:59 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Ofast

INCLUDES = includes
OBJ_PATH = obj


include srcs/conv/conv.mk
include srcs/flags/flags.mk
include srcs/libft/libft.mk
include	srcs/tools/tools.mk


all : $(NAME)

$(NAME) :	$(OBJ)
			ar rc $(NAME) $^
			ranlib $(NAME)
			
clean :
			rm -f $(OBJ)

fclean : 	clean
			rm -f $(NAME)
		
re :
	make fclean
	make all

.PHONY: all clean fclean re
