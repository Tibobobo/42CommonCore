/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:42 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/17 18:07:59 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int ft_error(int n)
{
    if (n == 1)
    {
		ft_putstr_fd("Error\nUsage: ./philo <number_of_philosophers> ", 2);
		ft_putstr_fd("<time_to_die> <time_to_eat> <time_to_sleep> ", 2);
		ft_putstr_fd("[number_of_necessary_meals]\n\n", 2);
		ft_putstr_fd("All values must be positive integers\n", 2);
    }
    if (n == 2)
        ft_putstr_fd("Malloc error", 2);
    return (-1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
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

int valid_args(char **av)
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

void    init_var(t_var *var, char **av)
{
    var->phil_nb = ft_atol(av[1]);
    var->ttd = ft_atol(av[2]);
    var->tte = ft_atol(av[3]);
    var->tts = ft_atol(av[4]);
    if (av[5] != NULL)
        var->nmeals = ft_atol(av[5]);
    else
        var->nmeals = -1;
    var->threads = malloc(sizeof(pthread_t) * var->phil_nb);
}

long long int	timestamp(t_philo *p)
{
	long long int ms;

	gettimeofday(&p->var->tv, NULL);
	ms = p->var->tv.tv_sec * 1000LL + p->var->tv.tv_usec/1000;
	return (ms - p->var->start);
}

void	*routine(t_philo *p)
{
	while (1)
	{
		p->left = 1;
		printf("%lld %u has taken a fork\n", timestamp(p), p->n);
		p->right = 1;
		printf("%lld %u has taken a fork\n", timestamp(p), p->n);
		printf("%lld %u is eating\n", timestamp(p), p->n);
		usleep(p->var->tte * 1000);
		p->left = 0;
		p->right = 0;
		printf("%lld %u is sleeping\n", timestamp(p), p->n);
		usleep(p->var->tts * 1000);
		printf("%lld %u is thinking\n", timestamp(p), p->n);
	}
}

void    start_threads(t_var *var, t_philo *philos)
{
    int	i;
	int	p;

	i = 0;
	p = var->phil_nb;
	while (p > 0)
	{
		pthread_create(&var->threads[i], NULL, &routine, &philos[i]);    //arg fonction void * ???
		p--;
		i++;
	}
}

int	init_philos(t_var *var, t_philo *philos)
{
	unsigned int	i;

	i = 0;
	philos = malloc(sizeof(t_philo) * var->phil_nb);
	if (philos == NULL)
		return (ft_error(2));
	while (i < var->phil_nb)
	{
		philos[i].dead = 0;
		philos[i].left = 0;
		philos[i].right = 0;
		philos[i].n = i + 1;
		philos[i].meals = 0;
		philos[i].var = var;
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
    t_var	var;
	t_philo	*philos;

	philos = NULL;
	gettimeofday(&var.tv, NULL);
	var.start = var.tv.tv_sec * 1000LL + var.tv.tv_usec/1000;
    if (ac > 6 || ac < 5 || valid_args(av) == 0)
        return(ft_error(1));
    init_var(&var, av);
    if (var.threads == NULL)
	{
        return (ft_error(2));
	}	
	if (init_philos(&var, philos) == -1)	//free var.threads
		return (-1);
    start_threads(&var, philos);
    pthread_join(var.threads[0], NULL);
    // free_all(&var, philos);
    return (0); 
}