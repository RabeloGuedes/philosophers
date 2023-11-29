CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
NAME = philo


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) main.c -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
