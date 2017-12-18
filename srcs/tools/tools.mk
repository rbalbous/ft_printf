# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tools.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 22:07:59 by rbalbous          #+#    #+#              #
#    Updated: 2017/12/18 18:29:22 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TOOLS =		ft_printf.c \
			add.c \
			ft_parse.c \
			addwp.c \
			pf_itoa.c \
			pf_uitoa.c \
			pf_uitoa_hexa.c
TOOLS_PATH = srcs/tools/

OBJ += $(addprefix $(OBJ_PATH)/, $(TOOLS:.c=.o))

$(OBJ_PATH)/%.o : $(TOOLS_PATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)	
