#include "push_swap.h"

// MAX 5 FONKSIYON KURALINA UYGUN
// 1. ft_reverse_rotate (rra, rrb)
void ft_reverse_rotate(t_stack **stack, char *op)
{
    t_stack *last;
    t_stack *second_last;

    if (!*stack || !(*stack)->next)
        return ;

    second_last = *stack;
    while (second_last->next->next)
        second_last = second_last->next;
    
    last = second_last->next;
    second_last->next = NULL;
    
    last->next = *stack;
    *stack = last;

    if (*op != '\0')
        write(STDOUT_FILENO, op, 4); // "rra\n" veya "rrb\n"
}

// 2. ft_do_rrr (rrr)
void ft_do_rrr(t_stack **a, t_stack **b)
{
    ft_reverse_rotate(a, ""); 
    ft_reverse_rotate(b, ""); 
    write(STDOUT_FILENO, "rrr\n", 4);
}