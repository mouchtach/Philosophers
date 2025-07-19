NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = philo_bonus.c \
		parssing_bonus.c \
		init_bonus.c \
		time_bonus.c \
		simulation_bonus.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%o : %.c philo_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re