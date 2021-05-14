NAME = run_test

CC = gcc
CFLAGS = -Wextra -Wall -Werror

SRCS =	*_test/*.c \
		./main.c
FW = ../framework/libunit.a
FW_INC = ../framework/inc/

FT_DIR = ../real_tests/libft/
FT_AR = ../real_tests/libft/libft.a
FT_INC = ../real_tests/libft/libft.h


OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}:
		cd "../framework" && make
		cd "../real_tests/libft" && make
		$(CC) $(CFLAGS) -I./inc $(SRCS) -I$(FW_INC) $(FW)  $(FT_AR) -o $(NAME)

clean:
	${RM} ${OBJS} ${BONUS_OBJS}
fclean: clean
	${RM} ${NAME}
	cd "../real_tests/libft" && make fclean
	cd "../framework" && make fclean
re:	fclean all
.PHONY: all clean fclean re bonus
