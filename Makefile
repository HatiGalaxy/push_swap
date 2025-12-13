NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
	utils/utils_atoi.c utils/utils_list.c utils/utils_free.c utils/utils_check.c \
	operations/swap.c operations/push.c operations/rotate.c operations/reverse_rotate.c \
	indexing/indexing.c \
	algorithms/radix.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
