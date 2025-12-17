/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hergul <hergul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:22:11 by hergul            #+#    #+#             */
/*   Updated: 2025/12/17 17:23:00 by hergul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack, char *op)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	if (*op != '\0')
		write(1, op, 3);
}

void	ft_do_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, "");
	ft_rotate(b, "");
	write(1, "rr\n", 3);
}
