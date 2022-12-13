/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:00:54 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/13 13:47:18 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

long int	ft_atol(const char *nptr)
{
	long int	i;
	long int	sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

void	smarter_rotate(t_stack **a, t_stack **b)
{
	if ((*a)->num > get_biggest(b) || (*a)->num < get_smallest(b))
		smart_rotate_b(b, get_biggest(b));
	else
		while (!((*a)->num > (*b)->num && (*a)->num < stack_last(b)))
		{
			if (get_position(b, get_closest((*a)->num, *b)) <= stack_size(*b) / 2)
				rb(b);
			else
				rrb(b);
		}
}

int	get_closest(int target, t_stack *b)
{
	t_stack	*elem;
	int		closest;

	closest = -2147483648;
	elem = b;
	while (elem != NULL)
	{
		if (elem->num < target && elem->num > closest)
			closest = elem->num;
		elem = elem->next;
	}
	return (closest);
}
