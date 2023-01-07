/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stuff_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:37:50 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/15 15:18:10 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*elem;

	if (new == NULL)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
	{
		elem = *stack;
		while (elem->next != NULL)
			elem = elem->next;
	elem->next = new;
	}
}

t_stack	*sorted_stack(t_stack *a)
{
	t_stack	*sorted;
	int		i;
	int		previous;

	sorted = NULL;
	i = 1;
	add_back(&sorted, new_elem(get_smallest(&a)));
	if (sorted == NULL)
		return (NULL);
	previous = get_smallest(&a);
	return (sorted_stack_2(sorted, a, previous, i));
}

t_stack	*sorted_stack_2(t_stack *sorted, t_stack *a, int previous, int i)
{
	int		temp;
	t_stack	*elem;

	while (i <= stack_size(a))
	{
		temp = 2147483647;
		elem = a;
		while (elem != NULL)
		{
			if (elem->num < temp && elem->num > previous)
				temp = elem->num;
			elem = elem->next;
		}
		add_back(&sorted, new_elem(temp));
		if (stack_size(sorted) != i + 1)
		{
			free_stack(sorted);
			return (NULL);
		}
		previous = temp;
		i++;
	}
	return (sorted);
}

void	index_a(t_stack **a, int size)
{
	t_stack	*sorted;
	t_stack	*begin;
	t_stack	*elem;
	int		i;

	i = 1;
	sorted = sorted_stack(*a);
	if (sorted == NULL)
		return ;
	begin = sorted;
	while (i <= size)
	{
		elem = *a;
		while (elem != NULL)
		{
			if (elem->num == sorted->num)
				elem->index = i;
			elem = elem->next;
		}
		i++;
		sorted = sorted->next;
	}
	free_stack(begin);
}

int	stack_last(t_stack **stack)
{
	t_stack	*elem;

	elem = *stack;
	if (elem == NULL)
		return (2147483647);
	while (elem->next != NULL)
		elem = elem->next;
	return (elem->num);
}
