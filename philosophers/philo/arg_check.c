/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:47:17 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/25 10:56:38 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_error(int n, t_var *var)
{
	if (n == 1)
	{
		ft_putstr_fd("Error\nUsage: ./philo <number_of_philosophers> ", 2);
		ft_putstr_fd("<time_to_die> <time_to_eat> <time_to_sleep> ", 2);
		ft_putstr_fd("[number_of_necessary_meals]\n\n", 2);
		ft_putstr_fd("All values must be positive integers\n", 2);
	}
	if (n == 2)
	{
		if (var->threads != NULL)
			free(var->threads);
		if (var->philos != NULL)
			free(var->philos);
		if (var->forks == NULL)
			free(var->forks);
		ft_putstr_fd("Malloc error\n", 2);
	}
	if (n == 3)
	{
		destroy_and_free(var);
		ft_putstr_fd("Mutex error\n", 2);
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

long long int	ft_atol(const char *nptr)
{
	long long int	i;
	long long int	sign;
	long long int	res;

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

int	valid_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			return (0);
		while (av[i][j] != '\0')
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		if (ft_strlen(av[i]) > 11)
			return (0);
		if (ft_atol(av[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}
