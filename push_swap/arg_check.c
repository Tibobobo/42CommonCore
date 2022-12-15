/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:11:55 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/15 13:55:25 by tgrasset         ###   ########.fr       */
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
		if (arg[i][j] == '\0')
			return (0);
		while (arg[i][j] != '\0')
		{
			if (!(arg[i][j] >= '0' && arg[i][j] <= '9'))
				return (0);
			j++;
		}
		if (ft_strlen(arg[i]) > 11)
			return (0);
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
