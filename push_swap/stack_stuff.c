/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:58:10 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/09 16:59:56 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*new_elem(int number)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (element == NULL)
		return (NULL);
	element->num = number;
	element->next = NULL;
	return (element);
}

t_stack	*init_stack_a(t_stack *a, int ac, char **av)
{
	int		i;
	t_stack	*begin;

	i = 1;
	a = new_elem(ft_atoi(av[i]));
	if (a == NULL)
		return (NULL);
	begin = a;
	i++;
	while (i < ac)
	{
		a->next = new_elem(ft_atoi(av[i]));
		if (a->next == NULL)
		{
			free_stack(begin);
			return (NULL);
		}
		a = a->next;
		i++;
	}
	a->next = NULL;
	return (begin);
}

int	free_stack(t_stack *stack)
{
	t_stack	*element;
	t_stack	*next_element;

	element = stack;
	while (element != NULL)
	{
		next_element = element->next;
		free(element);
		element = next_element;
	}
	stack = NULL;
	return (0);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
