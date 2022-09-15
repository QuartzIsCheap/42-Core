NAME		=	libftprintf.a

SRCS		=	libft/ft_printf.c \
				libft/ft_printf/generate_formatted_str.c \
				libft/ft_printf/printf_code_handling.c \
				libft/ft_abs.c \
				libft/ft_calloc.c \
				libft/ft_lltoa_base.c \
				libft/ft_log.c \
				libft/ft_memset.c \
				libft/ft_min.c \
				libft/ft_putstr_fd.c \
				libft/ft_strcat.c \
				libft/ft_strchr.c \
				libft/ft_strcpy.c \
				libft/ft_strdup.c \
				libft/ft_strjoin.c \
				libft/ft_strlen.c \
				libft/ft_strndup.c \
				libft/ft_strsnjoin.c \
				libft/ft_ulltoa_base.c
OBJS		=	${SRCS:.c=.o}

TEST		=	main.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g

RM			=	rm -f

%.o: %.c
				${CC} ${CFLAGS} -c $< -o $@

all:			${NAME}
${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}
fclean:			clean
				${RM} ${NAME} ${NAME}_tests a.out

re:				fclean all

test:			all
				${CC} ${CFLAGS} ${TEST} -L./ -lftprintf

.PHONY:			all clean fclean re test