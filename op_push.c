#include "push_swap.h"

// MAX 5 FONKSIYON KURALINA UYGUN
// 1. ft_push (pa, pb)
void ft_push(t_stack **src, t_stack **dest, char *op)
{
    t_stack *node_to_push;

    if (!*src)
        return ;

    node_to_push = *src;
    *src = (*src)->next;

    node_to_push->next = *dest;
    *dest = node_to_push;

    write(1, op, 3); // "pa\n" veya "pb\n"
}