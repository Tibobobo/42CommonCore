/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:54:39 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/09 17:21:21 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	rotate(t_stack **stack)
{
	int		temp;
	t_stack	*elem;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	elem = (*stack);
	temp = elem->num;
	while (elem->next != NULL)
	{	
		elem->num = elem->next->num;
		elem = elem->next;
	}
	elem->num = temp;
	return (1);
}

void	ra(t_stack **a)
{
	if (rotate(a) == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if (rotate(b) == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	if (rotate(a) == 1 && rotate(b) == 1)
		ft_printf("rr\n");
}
