NAME = philo

CC = cc
CFLAGS = -Wextra -Werror -Wall -g  -pthread
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC =	./utils.c \
		./init.c \
		./main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I. $(OBJ) -o $(NAME)
	@echo "$(GREEN)	PHILOSOPHERS COMPILED!$(RESET)"

RM = rm -f

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all