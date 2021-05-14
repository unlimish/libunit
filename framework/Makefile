NAME = libunit.a

SRCS = src/framework.c
SRCS += src/framework-utils.c

OBJS = ${SRCS:.c=.o}

#BONUS_OBJS = ${BONUS_SRCS:.c=.o}
all: ${NAME}

#bonus: ${OBJS} ${BONUS_OBJS}
#	ar rc ${NAME} $^

${NAME}: ${OBJS}
		@ar rc ${NAME} $^
		@printf "\e[32m>\e[m"
		@printf "\e[32;1mMake: \e[m\e[1mlibunit.a\e[m\n"

.c.o:
		@gcc -Wall -Wextra -Werror -I./inc -c $< -o $@
		@printf "\e[32m>\e[m"
clean:
		@${RM} ${OBJS} ${BONUS_OBJS}
		@printf "\e[31;1mDelete: \e[mlibunit/framework object files\n"
fclean: clean
		@${RM} ${NAME}
		@printf "\e[31;1mDelete: \e[mlibunit.a\n"
re:	fclean all
.PHONY: all clean fclean re bonus
