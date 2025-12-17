/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hergul <hergul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:28:38 by hergul            #+#    #+#             */
/*   Updated: 2025/12/17 21:00:22 by hergul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_index(t_stack *a)
{
	t_stack	*ptr1;
	t_stack	*ptr2;
	int				idx;

	ptr1 = a;
	while (ptr1)
	{
		idx = 0;
		ptr2 = a;
		while (ptr2)
		{
			if (ptr2->value < ptr1->value)
				idx++;
			ptr2 = ptr2->next;
		}
		ptr1->index = idx;
		ptr1 = ptr1->next;
	}
}

int	ft_is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
