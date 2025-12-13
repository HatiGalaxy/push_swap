#include "push_swap.h"

static int	max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = ft_lstsize(a) - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	bit;
	int	i;

	size = ft_lstsize(*a);
	bit = 0;
	while (bit < max_bits(*a))
	{
		i = 0;
		while (i < size)
		{
			if ((((*a)->index >> bit) & 1) == 0)
				pb(a, b, 1);
			else
				ra(a, 1);
			i++;
		}
		while (*b)
			pa(a, b, 1);
		bit++;
	}
}
