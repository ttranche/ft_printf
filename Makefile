NAME = libftprintf.a

LIBFT_PROJECT = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_PROJECT}/libft.a

SRCS =	ft_printf.c \
		ft_printf_parser.c \
		ft_printf_utils.c \
		type_c.c \
		type_f.c \
		type_handler.c \
		type_id.c \
		type_p.c \
		type_pc.c \
		type_s.c \
		type_utils.c \
		type_x.c

OBJS = ${SRCS:.c=.o}

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I${LIBFT_PROJECT}

bonus: ${NAME}

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) ${LIBFT_PROJECT}
			ar -rcs ${NAME} $(OBJS)

${LIBFT_PROJECT}:
			make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} all
			cp ${LIBFT_PATH} ${NAME}

clean:
			${RM} ${OBJS}
			make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} clean

fclean: clean
			${RM} ${NAME}
			make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} fclean

re: fclean all

.PHONY:		bonus all clean fclean re ${LIBFT_PROJECT}
