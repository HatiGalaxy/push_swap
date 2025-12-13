#include "push_swap.h"

static void	build_stack(t_stack **a, char **av)
{
	int		i;
	char	**spl;
	long	n;

	i = 1;
	while (av[i])
	{
		spl = ft_split(av[i], ' ');
		if (!spl)
			error_exit();
		int j = 0;
		while (spl[j])
		{
			n = ft_atol(spl[j]);
			add_back(a, new_node(n));
			j++;
		}
		free_split(spl);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	build_stack(&a, av);
	if (has_duplicate(a))
		error_exit();
	if (!is_sorted(a))
	{
		indexing(a);
		radix_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
