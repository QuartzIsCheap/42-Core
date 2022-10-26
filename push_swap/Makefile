NAME			=	push_swap

SRCS_DIR		=	src
SRCS			=	main.c \
					stack/parsing.c

BUILD_DIR		=	build
OBJS			=	${SRCS:%.c=${BUILD_DIR}/%.o}

LIBSDIR			=	dependencies/libs
INCLUDESDIR		=	dependencies/includes

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g

RM				=	rm -f

${BUILD_DIR}/%.o:	${SRCS_DIR}/%.c
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
