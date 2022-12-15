/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stuff_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:45:05 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/15 17:55:50 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

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
	return (smallest);
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
	return (biggest);
}

int	get_position(t_stack **stack, int target)
{
	t_stack	*elem;
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

int	next_number(t_stack *b, int index)
{
	while (b->index != index)
		b = b->next;
	return (b->num);
}

int	next_number_pos(t_stack *b, int target_index)
{
	int	i;

	i = 1;
	while (b != NULL)
	{
		if (b->index == target_index)
			return (i);
		b = b->next;
		i++;
	}
	return (-1);
}
