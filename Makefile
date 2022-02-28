NAME		= printf.a

SRC			= ft_printf.c

LIBFT		= libft/*.h \
			libft/*.c

OBJS		= ${SRC:.c=.o}

HEADER		= libft/libft.h \
			ft_printf.h

GCC			= gcc
GIT_LIBFT	= git clone https://github.com/Picalexdev/libft.git
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f
RM_DIR		= rm -rf

${NAME}:	${SRC}
			${GIT_LIBFT}
			${GCC} -c ${LIBFT} ${SRC}
			ar rc $(NAME) $(OBJS)
			${RM} *.o
			${RM_DIR} libft/

out:		${SRC}
			${GIT_LIBFT}
			rm libft/main.c
			gcc libft/*.c libft/*.h ft_printf.h ft_printf.c
			${RM_DIR} libft/

clean:		${SRC}
			${RM_DIR} libft/
			${RM} *.o