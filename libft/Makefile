NAME		=	libft.a

SRCS		=	abs.c \
				alpha_to_integer.c \
				char_alphas.c \
				char_ascii.c \
				char_digits.c \
				char_manipulation.c \
				char_others.c \
				char_visual_representations.c \
				int_to_str.c \
				max.c \
				mem_creates.c \
				mem_explorations.c \
				mem_writes.c \
				min.c \
				put_fd.c \
				str_apply.c \
				str_cats.c \
				str_cuts.c \
				str_char_finds.c \
				str_compares.c \
				str_copies.c \
				str_split.c \
				str_str_finds.c \
				str_trim.c \
				strlen.c
OBJS		=	${SRCS:.c=.o}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

%.o: %.c
				${CC} ${CFLAGS} -c $< -o $@

all:			${NAME}
${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}
fclean:			clean
				${RM} ${NAME} ${NAME}_tests

re:				fclean all

docs:			Doxyfile
				doxygen Doxyfile
				make -C docs/latex/
				mv docs/latex/refman.pdf docs/Documentation.pdf
				${RM} -r docs/latex

.PHONY:			all clean fclean re docs