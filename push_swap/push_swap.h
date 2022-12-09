/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:45:24 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/09 17:15:05 by tgrasset         ###   ########.fr       */
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
int			r_rotate(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
t_stack		*del_first(t_stack *first);
void		add_front(t_stack **stack, t_stack *new);

#endif
