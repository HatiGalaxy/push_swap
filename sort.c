/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hergul <hergul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:16:41 by hergul            #+#    #+#             */
/*   Updated: 2025/12/17 20:49:50 by hergul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_radix(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

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
			if ((((*a)->index >> i) & 1) == 0)
				ft_push(a, b, "pb\n");
			else
				ft_rotate(a, "ra\n");
			j++;
		}
		while (*b)
			ft_push(b, a, "pa\n");
		i++;
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_get_stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			ft_swap(a, "sa\n");
		return ;
	}
	if (size <= 5)
		ft_sort_small(a, b);
	else
		ft_sort_radix(a, b);
}
