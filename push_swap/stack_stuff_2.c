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

int	get_smallest(t_stack **stack)
{
	t_stack	*elem;
	int		smallest;

	smallest = 2147483647;
	elem = *stack;
	while (elem != NULL)
	{
		if (elem->num < smallest)
			smallest = elem->num;
		elem = elem->next;
	}
	return smallest;
}

int	get_biggest(t_stack **stack)
{
	t_stack	*elem;
	int		biggest;

	biggest = -2147483648;
	elem = *stack;
	while (elem != NULL)
	{
		if (elem->num > biggest)
			biggest = elem->num;
		elem = elem->next;
	}
	return biggest;
}

int	get_position(t_stack **stack, int target)
{
	t_stack *elem;
	int		pos;

	elem = *stack;
	pos = 1;
	while (elem != NULL && elem->num != target)
	{
		elem = elem->next;
		pos++;
	}
	if (elem == NULL)
		return (0);
	return (pos);
}