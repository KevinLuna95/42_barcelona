NAME 			= philo
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror -pthread

SOURCES 		= main.c ft_atoi.c
SOURCES_PATH	= ./src
OBJS_PATH		= ./build
HEADER			= $(SOURCES_PATH)/philo.h

all: $(NAME) 

OBJS = $(addprefix $(OBJS_PATH)/, ${SOURCES:.c=.o})

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER) Makefile
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re