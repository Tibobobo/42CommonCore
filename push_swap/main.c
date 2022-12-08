/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:11:30 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/08 12:43:52 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	is_sorted(int *a, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (valid_args(av) == 0 || no_doubles(av) == 0)
		return (arg_error());
	a = init_stack_a(a, ac, av);
	while (a != NULL)
	{
		ft_printf("%d\n", a->num);
		a = a->next;
	}
	return (0);
}
