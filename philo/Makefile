NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = philo.c \
		utils.c \
		time.c \
		simulation.c \
		parssing.c \
		data_init.c \
		all_clean.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%o : %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re