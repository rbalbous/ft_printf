# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    conv.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 21:09:17 by rbalbous          #+#    #+#              #
#    Updated: 2017/12/16 15:22:38 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/conv

CONVS = pf_s.c
SPATH = srcs/conv/s
CONVS_PATH = $(addprefix $(SPATH)/, $(CONVS))
OBJ = $(addprefix $(OBJ_PATH)/, $(CONVS:.c=.o))

CONVC = pf_c.c
CPATH = srcs/conv/c/
CONVC_PATH = $(addprefix $(CPATH), $(CONVC))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVC:.c=.o))

CONVD = 	pf_d.c \
			pf_cap_d.c \
			pf_hd.c \
			pf_hhd.c \
			pf_lld.c \
			pf_zd.c \
			pf_jd.c
DPATH = srcs/conv/d/
CONVD_PATH = $(addprefix srcs/conv/d/, $(CONVD))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVD:.c=.o))

CONVU = 	pf_u.c \
			pf_cap_u.c \
			pf_hhu.c \
			pf_hu.c \
			pf_llu.c \
			pf_ju.c \
			pf_zu.c
UPATH = srcs/conv/u/
CONVU_PATH = $(addprefix srcs/conv/u/, $(CONVU))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVU:.c=.o))


CONVO =		pf_o.c \
			pf_hho.c \
			pf_ho.c \
			pf_cap_o.c \
			pf_llo.c \
			pf_jo.c \
			pf_zo.c
OPATH = srcs/conv/o/
CONVO_PATH = $(addprefix srcs/conv/o/, $(CONVO))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVO:.c=.o))

CONVX =		pf_x.c \
			pf_cap_x.c \
			pf_llx.c \
			pf_lx.c \
			pf_hx.c \
			pf_hhx.c \
			pf_jx.c \
			pf_zx.c
XPATH = srcs/conv/x/
CONVX_PATH = $(addprefix srcs/conv/x/, $(CONVX))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVX:.c=.o))

$(OBJ_PATH)/%.o : $(SPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(CPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(DPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)		

$(OBJ_PATH)/%.o : $(UPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(OPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(XPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)
