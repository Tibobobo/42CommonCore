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
			smart_push(a, b);
			i++;
		}
		chunk_end = chunk_end + 45;
	}
	smart_rotate_b(b, get_biggest(b));
	while (*b != NULL)
		pa(a, b);
}