/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:42 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/24 12:32:14 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*routine(void *philo)
{
	t_philo *p;

	p = philo;
	if (p->var->nmeals == 0)
		return (NULL);
	if (p->var->phil_nb == 1)
		return (kill_lonely_philo(p), NULL);
	if (p->n % 2 == 0)
		usleep(p->var->tte * 1000);
	while (1)
	{
		while (1)
		{
			check_death(p);
			pthread_mutex_lock(&p->mutex->forks[p->n - 1]);
			if (p->var->forks[p->n - 1] == 1)
			{
				p->var->forks[p->n - 1] = 0;
				pthread_mutex_unlock(&p->mutex->forks[p->n - 1]);
				break ;
			}
			pthread_mutex_unlock(&p->mutex->forks[p->n - 1]);
			if (check_end(p) == 1)
				break ;
			usleep(50);
		}
		print(p, "has taken a fork\n");
		while (1)
		{
			check_death(p);
			if (p->n == p->var->phil_nb)
			{
				pthread_mutex_lock(&p->mutex->forks[0]);
				if (p->var->forks[0] == 1)
				{
					p->var->forks[0] = 0;
					pthread_mutex_unlock(&p->mutex->forks[0]);
					break ;
				}
				pthread_mutex_unlock(&p->mutex->forks[0]);
				if (check_end(p) == 1)
					break ;
				usleep(50);	
			}
			else
			{
				pthread_mutex_lock(&p->mutex->forks[p->n]);
				if (p->var->forks[p->n] == 1)
				{
					p->var->forks[p->n] = 0;
					pthread_mutex_unlock(&p->mutex->forks[p->n]);
					break ;
				}
				pthread_mutex_unlock(&p->mutex->forks[p->n]);
				if (check_end(p) == 1)
					break ;
				usleep(50);
			}
		}
		print(p, "has taken a fork\n");
		print(p, "is eating\n");
		pthread_mutex_lock(&p->mutex->end);
		p->last_meal = get_time();
		pthread_mutex_unlock(&p->mutex->end);
		ft_sleep(p->var->tte, p);
		p->meals++;
		pthread_mutex_lock(&p->mutex->end);
		if (p->meals == p->var->nmeals)
			p->var->finish++;
		pthread_mutex_unlock(&p->mutex->end);
		print(p, "is sleeping\n");
		pthread_mutex_lock(&p->mutex->forks[p->n - 1]);
		p->var->forks[p->n - 1] = 1;
		pthread_mutex_unlock(&p->mutex->forks[p->n - 1]);
		if (p->n == p->var->phil_nb)
		{
			pthread_mutex_lock(&p->mutex->forks[0]);
			p->var->forks[0] = 1;
			pthread_mutex_unlock(&p->mutex->forks[0]);
		}
		else
		{
			pthread_mutex_lock(&p->mutex->forks[p->n]);
			p->var->forks[p->n] = 1;
			pthread_mutex_unlock(&p->mutex->forks[p->n]);
		}
		ft_sleep(p->var->tts, p);
		print(p, "is thinking\n");
		if (check_end(p) == 1)
			break;
	}
	return (NULL);
}

int main(int ac, char **av)
{
    t_var	var;
	t_mutex mut;
	int		m;

    if (ac > 6 || ac < 5 || valid_args(av) == 0)
		return(ft_error(1, &var));
	if (ft_atol(av[1]) < 1)
		return(write(2, "Error\nSimulation needs at least 1 philo\n", 40), -1);
    init_var(&var, av);
    if (var.threads == NULL || var.philos == NULL || var.forks == NULL)
		return (ft_error(2, &var));
	init_philos(&mut, &var);
	m = init_mutex(&var);
	if (m == -1)
		return (ft_error(2, &var));
	if (m == 1)
		return (ft_error(3, &var));
	var.start = get_time();
    start_threads(&var);
    join_threads(&var);
    destroy_and_free(&var);
    return (0); 
}
