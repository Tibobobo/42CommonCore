/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:42:59 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/15 17:56:09 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	sort_500(t_stack **a, t_stack **b)
{
	int		chunk_end;
	int		i;

	chunk_end = 46;
	i = 0;
	while (*a != NULL)
	{
		while (i < chunk_end)
		{
			smart_rotate_a(a, chunk_end - 45, chunk_end);
			pb(a, b);
			if (stack_size(*b) > 1 && (*b)->index < chunk_end -23 && *a != NULL)
				rb(b);
			i++;
		}
		chunk_end = chunk_end + 45;
	}
	i = 0;
	smart_rotate_b(b, get_biggest(b));
	pa(a, b);
	fill_a(a, b, i);
	final_rotation(a, get_smallest(a));
}

void	fill_a(t_stack **a, t_stack **b, int i)
{
	while (*b != NULL)
	{
		if (next_number_pos(*b, (*a)->index - 1) != -1)
		{
			if ((*b)->index == (*a)->index - 1)
				pa(a, b);
			else if (i == 0 || (*b)->num > stack_last(a))
				i = i + push_to_bottom(a, b);
			else
				smart_rotate_b(b, next_number(*b, (*a)->index - 1));
		}
		else
		{
			while ((*b) != NULL && (*b)->num < stack_last(a) && i > 0)
			{
				rra(a);
				i--;
			}
			pa(a, b);
			while (check_sequence(*a, i) == 0)
				i = i + back_to_sequence(a);
		}
	}
}

int	push_to_bottom(t_stack **a, t_stack **b)
{
	pa(a, b);
	ra(a);
	return (1);
}

int	back_to_sequence(t_stack **a)
{
	ra(a);
	return (1);
}

int	check_sequence(t_stack *a, int bottom)
{
	int	count;
	int	size;

	count = 0;
	size = stack_size(a);
	size = size - bottom;
	while (a->next->next != NULL
		&& a->index == a->next->index - 1 && count < size)
	{
		count++;
		a = a->next;
	}
	if (count == size - 1)
		return (1);
	return (0);
}
