NAME		=	checker

SRCS		=	src/instruction/list/pushes.c \
				src/instruction/list/reverse_rotates.c \
				src/instruction/list/rotates.c \
				src/instruction/list/swaps.c \
				src/instruction/parsing.c \
				src/stack/creation/initialization.c \
				src/stack/creation/parsing.c \
				src/stack/memory.c \
				src/main.c

OBJS		=	${SRCS:.c=.o}

LIBSDIR		=	dependencies/libs
INCLUDESDIR	=	dependencies/includes

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

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

test:			all

re:				fclean all

.PHONY:			all clean fclean re test