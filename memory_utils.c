/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hergul <hergul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:26:27 by hergul            #+#    #+#             */
/*   Updated: 2025/12/17 17:27:11 by hergul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

void	ft_free_args(char **args, int is_single)
{
	int	i;

	if (!args || !is_single)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_cleanup(t_stack *a, t_stack *b, char **args, int is_single)
{
	ft_free_stack(&a);
	ft_free_stack(&b);
	ft_free_args(args, is_single);
}

void	ft_error_and_cleanup(t_stack *a, t_stack *b,
		char **args, int is_single)
{
	ft_cleanup(a, b, args, is_single);
	ft_error();
}
