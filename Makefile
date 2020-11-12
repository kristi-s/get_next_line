NAME = get_nl

SRCS = get_next_line.c get_next_line_utils.c main.c

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} -I get_next_line.h

all:	${NAME}

clean:
		${RM} ${NAME}

fclean: clean
		${RM} ${NAME}

re: fclean all

