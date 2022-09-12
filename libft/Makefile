NAME		=	libft.a

SRCS		=	ft_abs.c \
				ft_atoi.c \
				ft_atol.c \
				ft_aloll.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isblank.c \
				ft_iscntrl.c \
				ft_isdigit.c \
				ft_isgraph.c \
				ft_islower.c \
				ft_isprint.c \
				ft_ispunct.c \
				ft_isspace.c \
				ft_isupper.c \
				ft_isxdigit.c \
				ft_itoa.c \
				ft_lltoa.c \
				ft_max.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_min.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putllnbr_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strnchr.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strndup.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c
OBJS		=	${SRCS:.c=.o}

CC			=	cc
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