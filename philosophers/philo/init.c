/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:19:59 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/24 14:31:45 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_var(t_var *var, char **av)
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
	var->forks = malloc(sizeof(int) * var->phil_nb);
}

void	start_threads(t_var *var)
{
	int	i;
	int	p;

	i = 0;
	p = var->phil_nb;
	while (p > 0)
	{
		pthread_create(&var->threads[i], NULL, &routine, &var->philos[i]);
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
		var->philos[i].last_meal = get_time();
		var->forks[i] = 1;
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
		if (pthread_mutex_init(&var->philos->mutex->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&var->philos->mutex->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&var->philos->mutex->end, NULL) != 0)
		return (1);
	return (0);
}
