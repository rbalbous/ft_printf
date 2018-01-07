# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    conv.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 21:09:17 by rbalbous          #+#    #+#              #
#    Updated: 2018/01/07 17:10:59 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/conv

CONVS = pf_s.c \
		pf_cap_s.c
SPATH = srcs/conv/s
CONVS_PATH = $(addprefix $(SPATH)/, $(CONVS))
OBJ = $(addprefix $(OBJ_PATH)/, $(CONVS:.c=.o))

CONVC = pf_c.c \
		pf_cap_c.c
CPATH = srcs/conv/c
CONVC_PATH = $(addprefix srcs/conv/c/, $(CONVC))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVC:.c=.o))

CONVD = 	pf_d.c \
			pf_cap_d.c \
			pf_hd.c \
			pf_hhd.c \
			pf_lld.c \
			pf_zd.c \
			pf_jd.c
DPATH = srcs/conv/d
CONVD_PATH = $(addprefix srcs/conv/d/, $(CONVD))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVD:.c=.o))

CONVU = 	pf_u.c \
			pf_cap_u.c \
			pf_hhu.c \
			pf_hu.c \
			pf_llu.c \
			pf_ju.c \
			pf_zu.c
UPATH = srcs/conv/u
CONVU_PATH = $(addprefix srcs/conv/u/, $(CONVU))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVU:.c=.o))


CONVO =		pf_o.c \
			pf_hho.c \
			pf_ho.c \
			pf_cap_o.c \
			pf_llo.c \
			pf_jo.c \
			pf_zo.c
OPATH = srcs/conv/o
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
XPATH = srcs/conv/x
CONVX_PATH = $(addprefix srcs/conv/x/, $(CONVX))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVX:.c=.o))

CONVB =		pf_b.c
BPATH = srcs/conv/b
CONVB_PATH = $(addprefix srcs/conv/b/, $(CONVB))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVB:.c=.o))

CONVF =		pf_f.c \
			pf_cap_f.c \
			pf_cap_fl.c \
			pf_fl.c
FPATH = srcs/conv/f
CONVF_PATH = $(addprefix srcs/conv/f/, $(CONVF))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVF:.c=.o))

CONVE =		pf_e.c \
			pf_le.c \
			pf_cap_e.c \
			pf_cap_le.c
EPATH = srcs/conv/e
CONVE_PATH = $(addprefix srcs/conv/e/, $(CONVE))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVE:.c=.o))

CONVG =		pf_g.c
GPATH = srcs/conv/g
CONVG_PATH = $(addprefix srcs/conv/g/, $(CONVG))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVG:.c=.o))

CONVN =		pf_n.c \
			pf_hn.c \
			pf_hhn.c \
			pf_lln.c \
			pf_ln.c \
			pf_jn.c \
			pf_zn.c
NPATH = srcs/conv/n
CONVN_PATH = $(addprefix srcs/conv/n/, $(CONVN))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVN:.c=.o))

CONVA =		pf_a.c \
			pf_la.c \
			pf_cap_a.c
APATH = srcs/conv/a
CONVA_PATH = $(addprefix srcs/conv/a/, $(CONVA))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVA:.c=.o))

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

$(OBJ_PATH)/%.o : $(BPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(FPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(NPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(EPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(GPATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(APATH)/%.c $(INCLUDES)/ft_printf.h
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)
