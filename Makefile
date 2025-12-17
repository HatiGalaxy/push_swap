NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS = \
	push_swap.c \
	memory_utils.c \
	check_arg.c \
	split_utils.c \
	stack_init.c \
	index_sort.c \
	op_swap.c \
	op_push.c \
	op_rotate.c \
	op_rev_rotate.c \
	sort.c \
	sort_small.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all