#include "push_swap.h"

// MAX 5 FONKSIYON KURALINA UYGUN
// 1. ft_swap (sa, sb)
void ft_swap(t_stack **stack, char *op)
{
    t_stack *first;
    t_stack *second;

    if (!*stack || !(*stack)->next)
        return ;
    
    first = *stack;
    second = (*stack)->next;

    first->next = second->next;
    second->next = first;
    *stack = second;

    if (*op != '\0')
        write(STDOUT_FILENO, op, 3); // "sa\n" veya "sb\n"
}

// 2. ft_do_ss (ss)
void ft_do_ss(t_stack **a, t_stack **b)
{
    ft_swap(a, ""); 
    ft_swap(b, ""); 
    write(STDOUT_FILENO, "ss\n", 3);
}