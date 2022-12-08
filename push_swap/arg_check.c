/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:11:55 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/08 12:41:36 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	valid_args(char	**arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i] != NULL)
	{
		j = 0;
		if (arg[i][j] == '+' || arg[i][j] == '-')
			j++;
		while (arg[i][j] != '\0')
		{
			if (!(arg[i][j] >= '0' && arg[i][j] <= '9'))
				return (0);
			j++;
		}
		if (ft_atol(arg[i]) > 2147483647 || ft_atol(arg[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	no_doubles(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i + 1] != NULL)
	{
		j = i + 1;
		while (arg[j] != NULL)
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

t_stack	*new_elem(int number)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->num = number;
	element->next = NULL;
	return (element);
}

t_stack   *init_stack_a(t_stack *a, int ac, char **av)
{
    int i;
    t_stack *begin;

    i = 1;
    a = new_elem(ft_atoi(av[i]));
    begin = a;
    i++;
    while (i < ac)
    {
        a->next = new_elem(ft_atoi(av[i]));
        a = a->next;
        i++;
    }
    a->next = NULL;
    return (begin);
}
