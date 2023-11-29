CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
NAME = philo

SRC = utils.c params_checker.c error_handler.c

ROOT_DIR = ./
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) main.c -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(ROOT_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
