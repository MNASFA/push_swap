CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
SRCS = src/main.c src/push_swap.c src/stack_utils.c src/parsing.c src/operations_push.c src/operations_rotate.c \
		src/operations_rrotate.c src/operations_swap.c src/ft_split.c src/help_functions.c src/pushandsort_b.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all