/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:36:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/25 11:42:03 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork_0(t_philo *p)
{
	while (1)
	{
		check_death(p);
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
}

void	get_right_fork(t_philo *p)
{
	if (p->n == p->var->phil_nb)
		get_fork_0(p);
	else
	{
		while (1)
		{
			check_death(p);
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
}

void	print(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->mutex->end);
	if (p->var->dead == 0 && p->var->finish != p->var->phil_nb)
	{
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld #%u %s", get_time() - p->var->start, p->n, msg);
		pthread_mutex_unlock(&p->mutex->print);
	}
	pthread_mutex_unlock(&p->mutex->end);
}

long long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_sleep(long long int time, t_philo *p)
{
	long long int	i;

	i = get_time();
	(void)p;
	while (get_time() - i < time)
	{
		usleep(50);
		check_death(p);
	}
}
