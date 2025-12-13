#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atol(const char *s)
{
	long	sign = 1;
	long	r = 0;

	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		error_exit();
	while (*s)
	{
		if (*s < '0' || *s > '9')
			error_exit();
		r = r * 10 + (*s - '0');
		if (r * sign > INT_MAX || r * sign < INT_MIN)
			error_exit();
		s++;
	}
	return (r * sign);
}
