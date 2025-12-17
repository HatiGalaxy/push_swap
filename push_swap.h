/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hergul <hergul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:18:58 by hergul            #+#    #+#             */
/*   Updated: 2025/12/17 20:19:54 by hergul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> //sil

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void		ft_error(void);
void		ft_free_stack(t_stack **stack);
void		ft_free_args(char **args, int is_single);
void		ft_cleanup(t_stack *a, t_stack *b, char **args, int is_single);
void		ft_error_and_cleanup(t_stack *a, t_stack *b,
				char **args, int is_single);
long long	ft_atol(const char *str);
int			ft_is_valid_number(char *str);
void		ft_check_duplicates(t_stack *a, char **args, int is_single);
char		**ft_split_args(const char *s);
int			ft_get_stack_size(t_stack *stack);
void		ft_add_to_stack(t_stack **stack, int value);
t_stack		*ft_create_stack_a(char **args, int is_single_arg);
void		ft_assign_index(t_stack *a);
int			ft_is_sorted(t_stack *a);
void		ft_swap(t_stack **stack, char *op);
void		ft_do_ss(t_stack **a, t_stack **b);
void		ft_push(t_stack **src, t_stack **dest, char *op);
void		ft_rotate(t_stack **stack, char *op);
void		ft_do_rr(t_stack **a, t_stack **b);
void		ft_reverse_rotate(t_stack **stack, char *op);
void		ft_do_rrr(t_stack **a, t_stack **b);
void		ft_sort(t_stack **a, t_stack **b);
void		ft_sort_radix(t_stack **a, t_stack **b);
void		ft_sort_three(t_stack **a);
t_stack		*ft_find_min(t_stack *a);
void		ft_sort_small(t_stack **a, t_stack **b);

#endif
