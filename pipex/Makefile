NAME			=	pipex

SRCS_DIR		=	src
SRCS			=	commands/memory.c \
					commands/parsing.c \
					commands/resolving.c \
					paths/concatenation.c \
					paths/parsing.c \
					main.c

OBJS			=	${SRCS:%.c=${SRCS_DIR}/%.o}

LIBSDIR			=	libs
LIBFTDIR		=	${LIBSDIR}/libft

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g

RM				=	rm -f

TESTER			=	tester/tester

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

.PHONY:				all clean fclean re test
