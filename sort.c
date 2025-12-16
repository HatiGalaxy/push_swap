#include "push_swap.h"

// MAX 5 FONKSIYON KURALINA UYGUN
// 1. Radix Sort
void ft_sort_radix(t_stack **a, t_stack **b)
{
    int max_bits;
    int size;
    int i;
    int j;
    
    size = ft_get_stack_size(*a);
    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*a)->index >> i) & 1) == 1) 
                ft_rotate(a, "ra\n");
            else
                ft_push(a, b, "pb\n");
            j++;
        }
        while (*b)
            ft_push(b, a, "pa\n");
        i++;
    }
}

// 2. Ana Sıralama Fonksiyonu
void ft_sort(t_stack **a, t_stack **b)
{
    int size;

    size = ft_get_stack_size(*a);
    if (size <= 5)
        ft_sort_small(a, b);
    else
        ft_sort_radix(a, b);
}