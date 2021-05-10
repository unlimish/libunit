NAME = libunit.a

SRCS = framework.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}
all: ${NAME}

bonus: ${OBJS} ${BONUS_OBJS}
	ar rc ${NAME} $^

${NAME}: ${OBJS}
	ar rc ${NAME} $^

.c.o:
	gcc -Wall -Wextra -Werror -I./includes -c $< -o $@
clean:
	${RM} ${OBJS} ${BONUS_OBJS}
fclean: clean
	${RM} ${NAME}
re:	fclean all
.PHONY: all clean fclean re bonus
