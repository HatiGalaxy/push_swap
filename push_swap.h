#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>   
# include <unistd.h>   
# include <limits.h>   

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;


/* Utils */
long	ft_atol(const char *str);
void	error_exit(void);
void	free_stack(t_stack **stack);
void	free_split(char **s);
int		ft_lstsize(t_stack *lst);
t_stack	*lst_last(t_stack *stack);
void	add_back(t_stack **stack, t_stack *new_node);
t_stack	*new_node(int value);
int		is_sorted(t_stack *a);
int		has_duplicate(t_stack *a);
char	**ft_split(const char *s, char c);

/* Operations */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* Indexing */
void	indexing(t_stack *a);

/* Algorithm */
void	radix_sort(t_stack **a, t_stack **b);

#endif
