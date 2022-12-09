/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stuff_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:45:05 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/09 17:07:00 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

t_stack	*del_first(t_stack *first)
{
	t_stack	*temp;

	if (!first)
		return (NULL);
	temp = first;
	first = first->next;
	free(temp);
	return (first);
}

void	add_front(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	temp = new;
	if ((*stack) == NULL)
	{
		temp->next = NULL;
		*stack = temp;
	}
	temp->next = (*stack);
}
