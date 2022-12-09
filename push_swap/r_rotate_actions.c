/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:20:51 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/09 17:22:18 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	r_rotate(t_stack **stack)
{
	t_stack	*begin;
	t_stack	*elem;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	begin = *stack;
	elem = *stack;
	while (elem->next->next != NULL)
		elem = elem->next;
	*stack = elem->next;
	(*stack)->next = begin;
	elem->next = NULL;
	return (1);
}

void	rra(t_stack **a)
{
	if (r_rotate(a) == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	if (r_rotate(b) == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	if (r_rotate(a) == 1 && r_rotate(b) == 1)
		ft_printf("rrr\n");
}
