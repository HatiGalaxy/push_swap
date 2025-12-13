#include "push_swap.h"

static void	assign_index(t_stack *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == arr[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

static void	sort_array(int *arr, int size)
{
	int	i, j, tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	indexing(t_stack *a)
{
	int		*arr;
	int		i;
	int		size;
	t_stack	*tmp;

	size = ft_lstsize(a);
	arr = malloc(size * sizeof(int));
	if (!arr)
		error_exit();
	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_array(arr, size);
	assign_index(a, arr, size);
	free(arr);
}
