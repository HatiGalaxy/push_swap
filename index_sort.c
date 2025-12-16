#include "push_swap.h"

// MAX 5 FONKSIYON KURALINA UYGUN
// 1. İndeks Atama
void ft_assign_index(t_stack *a)
{
    t_stack *current;
    t_stack *min_val;
    int     index;
    int     size;

    size = ft_get_stack_size(a);
    index = 0;
    while (index < size)
    {
        current = a;
        min_val = NULL;
        while (current)
        {
            if (current->index == 0)
            {
                if (min_val == NULL || current->value < min_val->value)
                    min_val = current;
            }
            current = current->next;
        }
        if (min_val != NULL)
            min_val->index = index++;
    }
}

// 2. Sıralı Kontrol
int ft_is_sorted(t_stack *a)
{
    if (a == NULL)
        return (1);
    while (a->next)
    {
        if (a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}