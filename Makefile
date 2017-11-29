# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 17:34:45 by rbalbous          #+#    #+#              #
#    Updated: 2017/11/28 18:03:22 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCS =	ft_printf.c \
		add.c \
		ft_parse.c \
		create.c
SRC = $(addprefix srcs/, $(SRCS))

INCLUDES = includes/
INCLUDE = $(addprefix -I, $(INCLUDES))


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):	$(OBJ)
			@ar rc $(NAME) $^
			@ranlib $(NAME)
			@echo "\r\033[32;5;117m✓ libftprintf\033[0m\033[K"

%.o :		%.c
			@$(CC) -o $@ -c $< $(INCLUDE) $(FLAGS)
			@printf "\033[32;5;117m>"
			
clean:
			@rm -f $(OBJ)
			@echo "\r\033[38;5;202m✗ clean $(NAME).\033[0m\033[K"

fclean: clean
		@rm -f $(NAME)
		@echo "\r\033[38;5;196m✗ fclean $(NAME).\033[0m\033[K"
		
re : fclean all

.PHONY: all clean fclean re
