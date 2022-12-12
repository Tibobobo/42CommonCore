/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:11:30 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 11:48:40 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	if (valid_args(av) == 0 || no_doubles(av) == 0)
		return (arg_error());
	a = init_stack_a(a, ac, av);
	if (a == NULL)
		return (-1);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	index_a(&a, ac - 1);
	sort(&a, &b);
	ft_printf("stack a:\n");
	while (a != NULL)
	{
		ft_printf("%d\n", a->num);
		ft_printf("%d\n", a->index);
		a = a->next;
	}
	ft_printf("stack b:\n");
	while (b != NULL)
	{
		ft_printf("%d\n", b->num);
		b = b->next;
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
