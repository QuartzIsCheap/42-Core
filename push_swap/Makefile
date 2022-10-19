NAME		=	push_swap

SRCS		=	src/stack/creation/initialization.c \
				src/stack/creation/parsing.c \
				src/stack/memory.c \
				src/main.c
OBJS		=	${SRCS:.c=.o}

LIBSDIR		=	dependencies/libs
INCLUDESDIR	=	dependencies/includes

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g

RM			=	rm -f

%.o: %.c
				${CC} ${CFLAGS} -I${INCLUDESDIR} -c $< -o $@

all:			${NAME}
${NAME}:		${OBJS}
				${CC} ${CFLAGS} -I${INCLUDESDIR} ${OBJS} -L${LIBSDIR} -lft -o ${NAME}

clean:
				${RM} ${OBJS}
fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re test