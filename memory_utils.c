#include "push_swap.h"

// MAX 5 FONKSIYON KURALINA UYGUN
// 1. Hata Çıkışı
void    ft_error(void)
{
    write(STDERR_FILENO, "Error\n", 6);
    exit(EXIT_FAILURE);
}

// 2. Yığını Temizleme
void    ft_free_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *next_node;

    if (!stack || !*stack)
        return ;
    current = *stack;
    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *stack = NULL;
}

// 3. Argüman Dizisini Temizleme
void    ft_free_args(char **args, int is_single)
{
    int i;

    if (!args || !is_single)
        return ;

    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

// 4. Temiz Çıkış
void    ft_cleanup(t_stack *a, t_stack *b, char **args, int is_single)
{
    ft_free_stack(&a);
    ft_free_stack(&b);
    ft_free_args(args, is_single);
}

// 5. Hata Durumunda Temiz Çıkış
void    ft_error_and_cleanup(t_stack *a, t_stack *b, char **args, int is_single)
{
    ft_cleanup(a, b, args, is_single);
    ft_error();
}