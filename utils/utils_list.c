#include "push_swap.h"

t_stack	*new_node(int v)
{
	t_stack *n = malloc(sizeof(t_stack));
	if (!n) error_exit();
	n->value = v;
	n->index = -1;
	n->next = NULL;
	return (n);
}

int	ft_lstsize(t_stack *x)
{
	int i = 0;
	while (x)
	{
		i++;
		x = x->next;
	}
	return (i);
}

t_stack	*lst_last(t_stack *x)
{
	while (x && x->next)
		x = x->next;
	return (x);
}

void	add_back(t_stack **s, t_stack *n)
{
	t_stack *l;

	if (!*s)
	{
		*s = n;
		return ;
	}
	l = lst_last(*s);
	l->next = n;
}
