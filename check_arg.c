/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hergul <hergul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:29:55 by hergul            #+#    #+#             */
/*   Updated: 2025/12/17 17:30:54 by hergul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + (*str - '0');
		else
			return (LONG_MAX);
		str++;
	}
	return (res * sign);
}

int	ft_is_valid_number(char *str)
{
	long long	num;

	if (!str || *str == '\0')
		return (0);
	num = ft_atol(str);
	if (num == LONG_MAX && *str != '\0')
		return (0);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

void	ft_check_duplicates(t_stack *a, char **args, int is_single)
{
	t_stack	*current;
	t_stack	*runner;

	current = a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				ft_error_and_cleanup(a, NULL, args, is_single);
			runner = runner->next;
		}
		current = current->next;
	}
}
