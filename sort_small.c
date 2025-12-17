/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hergul <hergul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:12:08 by hergul            #+#    #+#             */
/*   Updated: 2025/12/17 17:13:35 by hergul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	int	t;
	int	m;
	int	b;

	t = (*a)->value;
	m = (*a)->next->value;
	b = (*a)->next->next->value;
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

t_stack	*ft_find_min(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

static int	ft_get_pos(t_stack *a, t_stack *target)
{
	int	pos;

	pos = 0;
	while (a != target)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

static void	ft_apply_rotation(t_stack **a, int pos, int size)
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

void	ft_sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_get_stack_size(*a);
	while (size > 3)
	{
		ft_apply_rotation(a, ft_get_pos(*a,
				ft_find_min(*a)), size);
		ft_push(a, b, "pb\n");
		size--;
	}
	ft_sort_three(a);
	while (*b)
		ft_push(b, a, "pa\n");
}
