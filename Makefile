NAME = libftprintf.a

SRCN = ft_printf.c
HDRN = ft_printf.h
BSRCN =

SRCPATH = ./
INCPATH = ./

SRCS = ${addprefix ${SRCPATH}, ${SRCN}}
BSRCS = ${addprefix ${SRCPATH}, ${BSRCN}}
HDRS = ${addprefix ${INCPATH}, ${HDRN}}

OBJ = ${SRCS:.c=.o}
BOBJ = ${BSRCS:.c=.o}
DPDS = ${SRCS:.c=.d} ${BSRCS:.c=.d}

CC = gcc

RM	= rm -f

CFLAG = -Wall -Wextra -Werror -D

all:	${NAME}

${NAME}:	${OBJ}
	${CC} ${CFLAG} -o $@ ${OBJ}

test:	${OBJ}
	${CC} ${CFLAG} -o $@ ${OBJ}

%.o : %.c
	${CC} ${CFLAG} -MMD -c $< -o $@ -I ${INCPATH}

include ${wildcard ${DPDS}}

debug:
	@make CFLAG="${CFLAG} -g3" SRCN="main.c ${SRCN}" test

bonus:
	@make SRCN="${BSRCN}" all

clean:
	${RM} ${OBJ} ${BOBJ} ${DPDS}
	cd ${LIBFT} && ${MAKE} clean

fclean:	clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT} clean

re:	fclean all

.PHONY: all bonus clean fclean re
