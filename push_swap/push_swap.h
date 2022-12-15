/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:45:24 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/15 16:40:47 by tgrasset         ###   ########.fr       */
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
int			free_stack(t_stack *stack);
int			stack_size(t_stack *stack);
int			stack_last(t_stack **stack);
t_stack		*sorted_stack(t_stack *a);
t_stack		*sorted_stack_2(t_stack *sorted, t_stack *a, int previous, int i);
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
void		sort(t_stack **a, t_stack **b);
void		sort_3(t_stack **a);
void		sort_4(t_stack **a, t_stack **b);
void		sort_5(t_stack **a, t_stack **b);
void		sort_100(t_stack **a, t_stack **b);
void		sort_500(t_stack **a, t_stack **b);
int			get_smartest_rotation(t_stack *a, int c_start, int c_end);
void		smart_rotate_a(t_stack **a, int start, int end);
void		smart_rotate_b(t_stack **b, int target);
void		final_rotation(t_stack **a, int target);
int			next_number_pos(t_stack *b, int target_index);
int			next_number(t_stack *b, int index);
int			check_sequence(t_stack *a, int bottom);

void	fill_a(t_stack **a, t_stack **b, int i);
#endif
