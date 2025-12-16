# Makefile

# Proje Adı (Konu gereği 'push_swap')
NAME = push_swap

# Derleme için zorunlu flag'ler
CFLAGS = -Wall -Wextra -Werror

# Tüm C kaynak dosyaları
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

# Object dosyaları (.c -> .o)
OBJS = $(SRCS:.c=.o)

# Varsayılan kural: all'ı çağırır
all: $(NAME)

# Ana derleme kuralı (relink yapmaz)
# Tüm .o dosyalarını derler ve tek bir yürütülebilir dosya oluşturur
$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

# Object dosyası oluşturma kuralı
# Her bir .c dosyasını ayrı ayrı derler
%.o: %.c
	cc $(CFLAGS) -c $< -o $@

# Tüm object dosyalarını siler
clean:
	rm -f $(OBJS)

# Tüm object dosyalarını ve yürütülebilir dosyayı (push_swap) siler
fclean: clean
	rm -f $(NAME)

# Her şeyi siler ve yeniden derler (Norminette'in 're' kuralı)
re: fclean all