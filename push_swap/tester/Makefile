NAME			=	tester

SRCS_DIR		=	src
SRCS			=	main.c \
					stack/instructions/pushes.c \
					stack/instructions/reverse_rotates.c \
					stack/instructions/rotates.c \
					stack/instructions/swaps.c \
					stack/parsing.c

OBJS			=	${SRCS:%.c=${SRCS_DIR}/%.o}

LIBSDIR			=	../libft
INCLUDESDIR		=	../libft

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

%.o:				%.c
					${CC} ${CFLAGS} -I${INCLUDESDIR} -c $< -o $@

all:				${NAME}
${NAME}:			${OBJS}
					${CC} ${CFLAGS} -I${INCLUDESDIR} ${OBJS} -L${LIBSDIR} -lft -o ${NAME}

clean:
					${RM} ${OBJS}
fclean:				clean
					${RM} ${NAME}

re:					fclean all

.PHONY:				all clean fclean re test
