/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:42 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/20 19:17:41 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	kill_lonely_philo(t_philo *p)
{
	p->var->dead = 1;
	printf("%lld #%u has taken a fork\n", get_time() - p->var->start, p->n);
	usleep(p->var->ttd * 1000);
	printf("%lld #%u has died\n", get_time() - p->var->start, p->n);
}

void    init_var(t_var *var, char **av)
{
    var->phil_nb = ft_atol(av[1]);
    var->ttd = ft_atol(av[2]);
    var->tte = ft_atol(av[3]);
    var->tts = ft_atol(av[4]);
	var->dead = 0;
	var->finish = 0;
    if (av[5] != NULL)
        var->nmeals = ft_atol(av[5]);
    else
        var->nmeals = -1;
    var->threads = malloc(sizeof(pthread_t) * var->phil_nb);
	var->philos = malloc(sizeof(t_philo) * var->phil_nb);
}

int		check_end(t_philo *p)
{
	pthread_mutex_lock(&p->mutex->end);
	if (p->var->dead == 1)
	{
		pthread_mutex_unlock(&p->mutex->end);
		return (1);
	}
	if (p->var->finish == p->var->phil_nb)
	{
		pthread_mutex_unlock(&p->mutex->end);
		return (1);
	}
	pthread_mutex_unlock(&p->mutex->end);
	return (0);
}

void	print(t_philo *p, char *msg)
{
	if (check_end(p) == 0)
	{
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld #%u ", get_time() - p->var->start, p->n);
		printf("%s", msg);
		pthread_mutex_unlock(&p->mutex->print);
	}
}

void	check_death(t_philo *p)
{
	long long int t;

	t = get_time();
	pthread_mutex_lock(&p->mutex->end);
	if (t - p->last_meal > p->var->ttd && p->var->dead == 0)
	{
		p->var->dead = 1;
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld #%u ", t - p->var->start, p->n);
		printf("has died\n");
		pthread_mutex_unlock(&p->mutex->print);
	}
	pthread_mutex_unlock(&p->mutex->end);

}

void    ft_sleep(long long int time, t_philo *p)
{
    long long int    i;

    i = get_time();
    while (get_time() - i < time)
	{
		usleep(50);
		check_death(p);
	}
}

void	*routine(void *philo)
{
	t_philo *p;

	p = philo;
	if (p->var->nmeals == 0)
		return (NULL);
	if (p->var->phil_nb == 1)
		return (kill_lonely_philo(p), NULL);
	if (p->n % 2 == 0)
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(&p->mutex->forks[p->n - 1]);
		print(p, "has taken a fork\n");
		if (p->n == p->var->phil_nb)
			pthread_mutex_lock(&p->mutex->forks[0]);
		else
			pthread_mutex_lock(&p->mutex->forks[p->n]);
		print(p, "has taken a fork\n");
		print(p, "is eating\n");
		p->last_meal = get_time();
		ft_sleep(p->var->tte, p);
		p->meals++;
		print(p, "is sleeping\n");
		pthread_mutex_lock(&p->mutex->end);
		if (p->meals == p->var->nmeals)
			p->var->finish++;
		pthread_mutex_unlock(&p->mutex->end);
		pthread_mutex_unlock(&p->mutex->forks[p->n - 1]);
		if (p->n == p->var->phil_nb)
			pthread_mutex_unlock(&p->mutex->forks[0]);
		else
			pthread_mutex_unlock(&p->mutex->forks[p->n]);
		ft_sleep(p->var->tts, p);
		print(p, "is thinking\n");
		if (check_end(p) == 1)
			break;
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
	pthread_mutex_init(&var->philos->mutex->end, NULL);
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
	pthread_mutex_destroy(&var->philos->mutex->end);
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

	var.start = get_time();
    if (ac > 6 || ac < 5 || valid_args(av) == 0)
		return(ft_error(1, &var));
	if (ft_atol(av[1]) < 1)
		return(write(2, "Error\nSimulation needs at least 1 philo\n", 40), -1);
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
