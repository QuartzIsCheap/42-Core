NAME			=	fractol

SRCS_DIR		=	src
SRCS			=	main.c \
					fractals/julia_sets/drawing.c \
					fractals/julia_sets/parameter_parsing.c \
					fractals/mandelbrot_set.c \
					fractals/palette.c \
					mlx_setup/hooks/close.c \
					mlx_setup/hooks/reset.c \
					mlx_setup/hooks/zoom.c \
					mlx_setup/controller_hooks.c \
					mlx_setup/obj_lifetimes.c \
					mlx_img.c

OBJS			=	${SRCS:%.c=${SRCS_DIR}/%.o}

LIBSDIR			=	libs
LIBFTDIR		=	${LIBSDIR}/libft
MLXDIR			=	${LIBSDIR}/mlx

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g

LINKS			=	-lft -lmlx -lXext -lX11

RM				=	rm -f

%.o:				%.c
					${CC} ${CFLAGS} -I${LIBFTDIR} -I${MLXDIR} -c $< -o $@

all:				${NAME}
${NAME}:			${OBJS} ${LIBFTDIR}/libft.a
					${CC} ${CFLAGS} -I${LIBFTDIR} -I${MLXDIR} ${OBJS} -L${LIBFTDIR} -L${MLXDIR} ${LINKS} -o ${NAME}

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
