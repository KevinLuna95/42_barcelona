SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJ = $(SRCS: .c=.o)
CFLAGS = -wextra -werror -wall

all: $(OBJ)
	gcc $(CFLAGS) $(OBJ)
clean:
	rm -r *.o
fclean:
	make clean | make