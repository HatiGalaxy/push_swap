#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	has_duplicate(t_stack *a)
{
	t_stack	*x;
	t_stack	*y;

	while (a)
	{
		x = a->next;
		while (x)
		{
			if (x->value == a->value)
				return (1);
			x = x->next;
		}
		a = a->next;
	}
	return (0);
}

static int	word_count(const char *s, char c)
{
	int	i = 0, count = 0;

	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	int		i = 0, j = 0, k;
	int		count = word_count(s, c);
	char	**out = malloc((count + 1) * sizeof(char *));

	if (!out)
		error_exit();
	while (i < count)
	{
		while (*s == c)
			s++;
		k = 0;
		while (s[k] && s[k] != c)
			k++;
		out[i] = malloc(k + 1);
		if (!out[i])
			error_exit();
		j = 0;
		while (j < k)
		{
			out[i][j] = s[j];
			j++;
		}
		out[i][j] = '\0';
		s += k;
		i++;
	}
	out[i] = NULL;
	return (out);
}
