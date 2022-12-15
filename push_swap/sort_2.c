/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:35:43 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/15 17:55:26 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	sort_100(t_stack **a, t_stack **b)
{
	int		chunk_end;
	int		i;

	chunk_end = 20;
	i = 0;
	while (*a != NULL)
	{
		while (i < chunk_end)
		{
			smart_rotate_a(a, chunk_end -19, chunk_end);
			pb(a, b);
			if (stack_size(*b) > 1 && (*b)->index < chunk_end -10)
				rb(b);
			i++;
		}
		chunk_end = chunk_end + 20;
	}
	while (*b != NULL)
	{
		smart_rotate_b(b, get_biggest(b));
		pa(a, b);
	}
}

void	smart_rotate_a(t_stack **a, int start, int end)
{
	if (*a != NULL)
	{
		if ((*a)->index >= start && (*a)->index <= end)
			return ;
		if (get_smartest_rotation(*a, start, end) == 1)
			while ((*a)->index < start || (*a)->index > end)
				ra(a);
		else
			while ((*a)->index < start || (*a)->index > end)
				rra(a);
	}
}

void	smart_rotate_b(t_stack **b, int target)
{
	if ((*b)->num == target)
		return ;
	if (get_position(b, target) <= stack_size(*b) / 2)
		while ((*b)->num != target)
			rb(b);
	else
		while ((*b)->num != target)
			rrb(b);
}

int	get_smartest_rotation(t_stack *a, int c_start, int c_end)
{
	t_stack	*elem;
	int		begin_count;
	int		end_count;
	int		total_count;

	elem = a;
	begin_count = 0;
	end_count = 0;
	total_count = 0;
	while (elem != NULL && (elem->index < c_start || elem->index > c_end))
	{
		begin_count++;
		elem = elem->next;
	}
	while (a != NULL && end_count < 20)
	{
		if (a->index >= c_start && a->index <= c_end)
			end_count++;
		a = a->next;
		total_count++;
	}
	end_count = stack_size(a) - total_count;
	if (begin_count <= end_count)
		return (1);
	return (-1);
}

void	final_rotation(t_stack **a, int target)
{
	if ((*a)->num == target)
		return ;
	if (get_position(a, target) <= stack_size(*a) / 2)
		while ((*a)->num != target)
			ra(a);
	else
		while ((*a)->num != target)
			rra(a);
}
