#include "push_swap.h"

// MAX 5 FONKSIYON KURALINA UYGUN
// 1. ft_rotate (ra, rb)
void ft_rotate(t_stack **stack, char *op)
{
    t_stack *first;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return ;

    first = *stack;
    *stack = (*stack)->next;
    first->next = NULL;

    last = *stack;
    while (last->next)
        last = last->next;
    
    last->next = first;

    if (*op != '\0')
        write(1, op, 3); // "ra\n" veya "rb\n"
}

// 2. ft_do_rr (rr)
void ft_do_rr(t_stack **a, t_stack **b)
{
    ft_rotate(a, ""); 
    ft_rotate(b, ""); 
    write(1, "rr\n", 3);
}