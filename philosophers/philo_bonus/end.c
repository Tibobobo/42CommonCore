/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:28:18 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/25 16:35:28 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_philo *p)
{
	sem_wait(p->sem->end);
	if (p->var->dead == 1 || p->meals == p->var->nmeals)
	{
		sem_post(p->sem->end);
		return (1);
	}
	sem_post(p->sem->end);
	return (0);
}

void	destroy(t_var *var)
{
	sem_close(var->philos[0].sem->end);
	sem_close(var->philos[0].sem->print);
	sem_close(var->philos[0].sem->forks);
}

void	*check_death(void *philo)
{
	long long int	t;
	t_philo			*p;

	p = philo;
	while (1)
	{
		t = get_time();
		sem_wait(p->sem->end);
		if (t - p->last_meal > p->var->ttd)
		{
			p->var->dead = 1;
			sem_wait(p->sem->print);
			printf("%lld #%u died\n", t - p->var->start, p->n);
			sem_post(p->sem->print);
			sem_post(p->sem->end);
			return (NULL);
		}
		sem_post(p->sem->end);
		if (check_end(p) == 1)
		{
			return (NULL);
		}
		usleep(5000);
	}
}
