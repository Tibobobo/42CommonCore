/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:45:24 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/09 17:23:38 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}					t_stack;

long int	ft_atol(const char *nptr);
int			valid_args(char	**arg);
int			no_doubles(char **arg);
int			arg_error(void);
t_stack		*init_stack_a(t_stack *a, int ac, char **av);
t_stack		*new_elem(int num);
int			is_sorted(t_stack *stack);
int			is_rev_sorted(t_stack *stack);
int			free_stack(t_stack *stack);
int			stack_size(t_stack *stack);
int			stack_last(t_stack **stack);
t_stack		*sorted_stack(t_stack *a);
void		index_a(t_stack **a, int size);
int			get_smallest(t_stack **stack);
int			get_biggest(t_stack **stack);
int			get_position(t_stack **stack, int target);
int			swap(t_stack **stack);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
int			push(t_stack **src, t_stack **dst);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
int			rotate(t_stack **stack);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
int			r_rotate(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
t_stack		*del_first(t_stack *first);
void		add_front(t_stack **stack, t_stack *new);
void		sort(t_stack **a, t_stack **b);
void		sort_3(t_stack **a);
void		sort_4(t_stack **a, t_stack **b);
void		sort_5(t_stack **a, t_stack **b);
void		sort_100(t_stack **a, t_stack **b);
void		sort_500(t_stack **a, t_stack **b);
int			get_smartest_rotation(t_stack *a, int c_start, int c_end);
void		smart_push(t_stack **a, t_stack **b);
void		smart_rotate_a(t_stack **a, int start, int end);
void		smart_rotate_b(t_stack **b, int target);
void		smarter_rotate(t_stack **a, t_stack **b);
int			get_closest(int target, t_stack *b);

#endif
