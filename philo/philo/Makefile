NAME 			= philo
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror -pthread #-fsanitize=thread -g

SOURCES 		= main.c init-check_input.c time-print.c getters.c setters.c checkers_helpers.c
OBJS_PATH		= ./build
HEADER			= philo.h

all: $(NAME)

OBJS = $(addprefix $(OBJS_PATH)/, ${SOURCES:.c=.o})

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_PATH)/%.o: %.c $(HEADER) Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re