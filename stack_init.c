/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hergul <hergul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:13:55 by hergul            #+#    #+#             */
/*   Updated: 2025/12/17 17:14:56 by hergul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static t_stack	*ft_create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_to_stack(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = ft_create_node(value);
	if (!new_node)
		ft_error_and_cleanup(*stack, NULL, NULL, 0);
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

t_stack	*ft_create_stack_a(char **args, int is_single_arg)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 0;
	while (args[i])
	{
		if (!ft_is_valid_number(args[i]))
			ft_error_and_cleanup(a, NULL, args, is_single_arg);
		ft_add_to_stack(&a, (int)ft_atol(args[i]));
		i++;
	}
	ft_check_duplicates(a, args, is_single_arg);
	return (a);
}
