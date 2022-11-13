NAME			=	fractol

SRCS_DIR		=	src
SRCS			=	main.c

OBJS			=	${SRCS:%.c=${SRCS_DIR}/%.o}

LIBFTDIR		=	libft

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

%.o:				%.c
					${CC} ${CFLAGS} -I${LIBFTDIR} -c $< -o $@

all:				${NAME}
${NAME}:			${OBJS} ${LIBFTDIR}/libft.a
					${CC} ${CFLAGS} -I${LIBFTDIR} ${OBJS} -L${LIBFTDIR} -lft -o ${NAME}

${LIBFTDIR}/libft.a:
					make -C ${LIBFTDIR} libft.a

clean:
					${RM} ${OBJS}
					make -C ${LIBFTDIR} clean
fclean:				clean
					${RM} ${NAME}
					make -C ${LIBFTDIR} fclean

re:					fclean all

test:				${NAME}

.PHONY:				all clean fclean re test
