# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    flags.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 21:50:54 by rbalbous          #+#    #+#              #
#    Updated: 2017/12/16 15:10:34 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS_LEN = ft_j.c \
			pf_l.c \
			pf_h.c \
			pf_z.c
LEN_PATH = srcs/flags/length
FLAGS_LEN_PATH = $(addprefix srcs/flags/length/, $(FLAGS_LEN))
OBJ += $(addprefix $(OBJ_PATH)/, $(LEN:.c=.o))	
		
FLAGS_OTH =	pf_hashtag.c \
			ft_minus.c \
			ft_plus.c \
			ft_preci.c \
			pf_fwidth.c \
			ft_space.c \
			ft_zero.c \
			pf_percent.c \
			pf_empty.c
OTH_PATH = srcs/flags/length
FLAGS_OTH_PATH = $(addprefix srcs/flags/others/, $(FLAGS_OTH))
OBJ += $(addprefix $(OBJ_PATH)/, $(OTH:.c=.o))

$(OBJ_PATH)/%.o : $(LENPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(OTHPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)
