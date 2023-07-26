NAME = rush-02
SRCS = rush-02.c utils.c spell.c spell_utils.c dict_parse.c
OBJS = ${SRC:.c=.o}
FLAGS = -Wall -Werror -Wextra
all:	${NAME}
${NAME}: ${OBJS}
	cc -o ${NAME} ${SRCS} -g -Iincludes ${FLAGS}
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all
.PHONY: all clean fclean