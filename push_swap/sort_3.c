/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:42:59 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/13 15:43:01 by tgrasset         ###   ########.fr       */
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
			if (stack_size(*b) > 1 && (*b)->index < chunk_end -23)
				rb(b);
			i++;
		}
		chunk_end = chunk_end + 45;
	}
	i = 0;
//	pa(a, b);
//	pa(a, b);
//	if ((*a)->num > (*a)->next->num)
//		sa(a);
	while (*b != NULL || i > 0)
	{
		if ((*b)->num == get_biggest(b))
			pa(a, b);
		else if (i == 0 || (*b)->num > stack_last(a))
		{
			pa(a, b);   // OU INCREMENTER i ??? ON Y EST PRESQUE BORDEL !
			ra(a);
		}
		else
		{
			smart_rotate_b(b, get_biggest(b));
			pa(a, b);
		}

//		smart_rotate_b(b, get_biggest(b));
//		pa(a, b);
	}	
}