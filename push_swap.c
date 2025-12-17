/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hergul <hergul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:09:08 by hergul            #+#    #+#             */
/*   Updated: 2025/12/17 17:11:01 by hergul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_prepare_args(char **argv, int argc, int *is_single)
{
	char	**args;

	if (argc == 2)
	{
		*is_single = 1;
		args = ft_split_args(argv[1]);
		if (!args)
			ft_error();
		return (args);
	}
	*is_single = 0;
	return (argv + 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		is_single_arg;

	if (argc == 1)
		return (0);
	args = ft_prepare_args(argv, argc, &is_single_arg);
	a = ft_create_stack_a(args, is_single_arg);
	b = NULL;
	ft_assign_index(a);
	if (ft_is_sorted(a))
	{
		ft_cleanup(a, b, args, is_single_arg);
		return (0);
	}
	ft_sort(&a, &b);
	ft_cleanup(a, b, args, is_single_arg);
	return (0);
}
