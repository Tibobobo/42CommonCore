/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:45:06 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/07 17:54:52 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

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

void	push_swap(int ac, char **av)
{
	int	*a;
	int	*b;
	int	i;

	a = malloc(sizeof(int) * (ac - 1));
	if (!a)
		return ;
	b = malloc(sizeof(int) * (ac - 1));
	if (!b)
	{
		free(a);
		return ;
	}
	i = 0;
	while (i < ac)
	{
		a[i] = ft_atoi(av[i + 1]);
		b[i] = 0;  //Probleme avec 0 qui est un nombre, faudrait mettre autre chose...
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (1);
	if (valid_args(av) == 0 || no_doubles(av) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	else
		push_swap(ac, av);
	return (0);
}
