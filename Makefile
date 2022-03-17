NAME		= printf.a

SRC			= ft_printf.c

LIBFT		= libft/*.h \
			libft/*.c

OBJS		= ${SRC:.c=.o}

HEADER		= libft/libft.h \
			ft_printf.h

GCC			= gcc
GIT_LIBFT	= git clone https://github.com/Picalexdev/libft.git
GIT_FETCH_LIBFT	= git fetch https://github.com/Picalexdev/libft.git
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f
RM_DIR		= rm -rf

${NAME}:	${SRC}
			${GIT_LIBFT}
			${GCC} -c ${LIBFT} ${SRC}
			ar rc $(NAME) $(OBJS)
			${RM} *.o

clone:		${SRC}
			${GIT_LIBFT}

out:		${SRC}
			gcc libft/*.c libft/*.h ft_printf.h ft_printf.c
			${RM} *.o *.a

upd:		${SRC}
			${GIT_FETCH_LIBFT}
			gcc libft/*.c libft/*.h ft_printf.h ft_printf.c
			${RM} *.o *.a

clean:		${SRC}
			${RM_DIR} libft/
			${RM} *.o *.a