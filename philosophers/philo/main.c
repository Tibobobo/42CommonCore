/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:42 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/18 18:00:23 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_var(t_var *var, char **av)
{
    var->phil_nb = ft_atol(av[1]);
    var->ttd = ft_atol(av[2]);
    var->tte = ft_atol(av[3]);
    var->tts = ft_atol(av[4]);
	var->dead = 0;
    if (av[5] != NULL)
        var->nmeals = ft_atol(av[5]);
    else
        var->nmeals = -1;
    var->threads = malloc(sizeof(pthread_t) * var->phil_nb);
	var->philos = malloc(sizeof(t_philo) * var->phil_nb);
}

long long int	timestamp(t_philo *p)
{
	long long int ms;

	gettimeofday(&p->var->tv, NULL);
	ms = p->var->tv.tv_sec * 1000LL + p->var->tv.tv_usec/1000;
	return (ms - p->var->start);
}

void	*last_philo(t_philo *p)
{
	while (1)
	{
		pthread_mutex_lock(&p->mutex->forks[0]);
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld %u has taken a fork %u\n", timestamp(p), p->n, p->n - 1);
		pthread_mutex_unlock(&p->mutex->print);
		pthread_mutex_lock(&p->mutex->forks[p->n - 1]);
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld %u has taken a fork %u\n", timestamp(p), p->n, 0);
		printf("%lld %u is eating\n", timestamp(p), p->n);
		pthread_mutex_unlock(&p->mutex->print);
		p->last_meal = timestamp(p);
		usleep(p->var->tte * 1000);
		p->meals++;
		if (p->meals == p->var->nmeals)
		{
			pthread_mutex_unlock(&p->mutex->forks[p->n - 1]);
			pthread_mutex_unlock(&p->mutex->forks[0]);
			break;
		}
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld %u is sleeping\n", timestamp(p), p->n);
		pthread_mutex_unlock(&p->mutex->print);
		pthread_mutex_unlock(&p->mutex->forks[0]);
		pthread_mutex_unlock(&p->mutex->forks[p->n - 1]);
		usleep(p->var->tts * 1000);
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld %u is thinking\n", timestamp(p), p->n);
		pthread_mutex_unlock(&p->mutex->print);
	}
	return (NULL);
}

void	*routine(void *philo)
{
	t_philo *p;

	p = philo;
	if (p->n % 2 == 0)
		usleep(1000);
	// if (p->var->phil_nb == 1)			peut etre a gerer a la main
	// 	return (one_philo(p));
	if (p->n == p->var->phil_nb)
		return (last_philo(p));
	while (1)
	{
		pthread_mutex_lock(&p->mutex->forks[p->n - 1]);
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld %u has taken a fork %u\n", timestamp(p), p->n, p->n - 1);
		pthread_mutex_unlock(&p->mutex->print);
		pthread_mutex_lock(&p->mutex->forks[p->n]);
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld %u has taken a fork %u\n", timestamp(p), p->n, p->n);
		printf("%lld %u is eating\n", timestamp(p), p->n);
		pthread_mutex_unlock(&p->mutex->print);
		p->last_meal = timestamp(p);
		usleep(p->var->tte * 1000);
		p->meals++;
		if (p->meals == p->var->nmeals)
		{
			pthread_mutex_unlock(&p->mutex->forks[p->n - 1]);
			pthread_mutex_unlock(&p->mutex->forks[p->n]);
			break;
		}
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld %u is sleeping\n", timestamp(p), p->n);
		pthread_mutex_unlock(&p->mutex->print);
		pthread_mutex_unlock(&p->mutex->forks[p->n - 1]);
		pthread_mutex_unlock(&p->mutex->forks[p->n]);
		usleep(p->var->tts * 1000);
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld %u is thinking\n", timestamp(p), p->n);
		pthread_mutex_unlock(&p->mutex->print);
	}
	return (NULL);
}

void    start_threads(t_var *var)
{
    int	i;
	int	p;

	i = 0;
	p = var->phil_nb;
	while (p > 0)
	{
		pthread_create(&var->threads[i], NULL, &routine, &var->philos[i]);    //a securiser
		p--;
		i++;
	}
}

void	init_philos(t_mutex *mut, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->phil_nb)
	{
		var->philos[i].dead = 0;
		var->philos[i].n = i + 1;
		var->philos[i].meals = 0;
		var->philos[i].var = var;
		var->philos[i].mutex = mut;
		i++;
	}
}

int	init_mutex(t_var *var)
{
	int	i;

	i = 0;
	var->philos->mutex->forks = malloc(sizeof(pthread_mutex_t) * var->phil_nb);
	if (var->philos->mutex->forks == NULL)
		return (-1);
	while (i < var->phil_nb)
	{
		pthread_mutex_init(&var->philos->mutex->forks[i], NULL);     //a securiser ?
		i++;
	}
	pthread_mutex_init(&var->philos->mutex->print, NULL);
	return (0);
}

void	join_threads(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->phil_nb)
	{
		pthread_join(var->threads[i], NULL);		//a securiser
		i++;
	}
}

void	destroy_and_free(t_var *var)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&var->philos->mutex->print);
	while (i < var->phil_nb)
	{
		pthread_mutex_destroy(&var->philos->mutex->forks[i]);
		i++;
	}
	free(var->philos->mutex->forks);
	free(var->philos);
	free(var->threads);
}

int main(int ac, char **av)
{
    t_var	var;
	t_mutex mut;

	gettimeofday(&var.tv, NULL);
	var.start = var.tv.tv_sec * 1000LL + var.tv.tv_usec/1000;
    if (ac > 6 || ac < 5 || valid_args(av) == 0)
        return(ft_error(1, &var));
    init_var(&var, av);
    if (var.threads == NULL || var.philos == NULL)
		return (ft_error(2, &var));
	init_philos(&mut, &var);
	if (init_mutex(&var) == -1)
		return (ft_error(2, &var));
    start_threads(&var);
    join_threads(&var);
    destroy_and_free(&var);
    return (0); 
}
