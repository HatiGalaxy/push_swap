#include "push_swap.h"

void	free_stack(t_stack **s)
{
	t_stack *tmp;

	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}

void	free_split(char **s)
{
	int	i = 0;

	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
