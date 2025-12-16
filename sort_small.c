#include "push_swap.h"

// MAX 5 FONKSIYON KURALINA UYGUN
// 1. 3 Eleman Sıralama
void ft_sort_three(t_stack **a)
{
    int t = (*a)->value;
    int m = (*a)->next->value;
    int b = (*a)->next->next->value;

    if (t > m && m < b && t < b)
        ft_swap(a, "sa\n");
    else if (t > m && m > b && t > b)
    {
        ft_swap(a, "sa\n");
        ft_reverse_rotate(a, "rra\n");
    }
    else if (t > m && m < b && t > b)
        ft_rotate(a, "ra\n");
    else if (t < m && m > b && t < b)
    {
        ft_swap(a, "sa\n");
        ft_rotate(a, "ra\n");
    }
    else if (t < m && m > b && t > b)
        ft_reverse_rotate(a, "rra\n");
}

// 2. En Küçük Elemanı Bulma
t_stack *ft_find_min(t_stack *a)
{
    t_stack *min;
    
    min = a;
    while (a)
    {
        if (a->value < min->value)
            min = a;
        a = a->next;
    }
    return (min);
}

// 3. Konumu Bulma
static int ft_get_pos(t_stack *a, t_stack *target)
{
    int pos;
    
    pos = 0;
    while (a != target)
    {
        a = a->next;
        pos++;
    }
    return (pos);
}

// 4. Rotasyon Uygulama
static void ft_apply_rotation(t_stack **a, int pos, int size)
{
    if (pos <= (size / 2))
    {
        while (pos-- > 0)
            ft_rotate(a, "ra\n");
    }
    else
    {
        while (pos++ < size)
            ft_reverse_rotate(a, "rra\n");
    }
}

// 5. 4/5 Eleman Sıralama
void ft_sort_small(t_stack **a, t_stack **b)
{
    int size;
    
    size = ft_get_stack_size(*a);
    while (size > 3)
    {
        ft_apply_rotation(a, ft_get_pos(*a, ft_find_min(*a)), size);
        ft_push(a, b, "pb\n");
        size--;
    }

    ft_sort_three(a);

    while (*b)
        ft_push(b, a, "pa\n");
}