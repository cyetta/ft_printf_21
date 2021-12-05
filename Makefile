NAME = libftprintf.a

SRCN = ft_printf.c ft_printf_char.c ft_printf_dec.c ft_printf_hex.c
HDRN = ft_printf.h
BSRCN = ft_printf_bonus.c ft_printf_char_bonus.c ft_printf_dec.c ft_printf_hex.c

LIBFTNAME = ft
LIBFTPATH = ./libft
LIBFTA = ${LIBFTPATH}/lib${LIBFTNAME}.a
SRCPATH =
INCPATH = ${LIBFTPATH}

SRCS = ${addprefix ${SRCPATH}, ${SRCN}}
BSRCS = ${addprefix ${SRCPATH}, ${BSRCN}}
HDRS = ${addprefix ${INCPATH}, ${HDRN}}

OBJ = ${SRCS:.c=.o}
BOBJ = ${BSRCS:.c=.o}
DPDS = ${SRCS:.c=.d} ${BSRCS:.c=.d}

CC = gcc

RM	= rm -f

CFLAG = -Wall -Wextra -Werror

all:	${NAME}

${NAME}:	libft ${OBJ}
	cp ${LIBFTA} ${NAME}
	ar rcs ${NAME} ${OBJ}

%.o : %.c
	${CC} ${CFLAG} -MMD -c $< -o $@ -I${INCPATH}

include ${wildcard ${DPDS}}

libft:
	${MAKE} -C ${LIBFTPATH} NAME="lib${LIBFTNAME}.a"

test:	${OBJ}
	${CC} ${CFLAG} -o $@ -L${LIBFTPATH} ${OBJ} -l${LIBFTNAME}

bonus: libft ${BOBJ}
	cp ${LIBFTA} ${NAME}
	ar rcs ${NAME} ${BOBJ}

debug: libft
	${MAKE} CFLAG="${CFLAG} -g3" SRCN="${BSRCN} main.c" test

clean:
	${RM} ${OBJ} ${BOBJ} ${DPDS}
	cd ${LIBFTPATH} && ${MAKE} NAME="lib${LIBFTNAME}.a" clean

fclean:	clean
	${RM} ${NAME} test main.o main.d
	${MAKE} -C ${LIBFTPATH} NAME="lib${LIBFTNAME}.a" fclean

re:	fclean all

.PHONY: all bonus clean fclean re debug libft
