/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:28:18 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/27 10:28:20 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*kill_children2(void *v)
{
	t_var	*var;
	int	i;
	
	var = v;
	i = 0;
	while (i < var->phil_nb)
	{
		sem_wait(var->philos[0].sem->finish);
		i++;
	}
	i = 0;
	while (i < var->phil_nb)
	{
		kill(var->pid[i], SIGKILL);
		i++;
	}
	return (NULL);
}

void	*kill_children(void *v)
{
	t_var	*var;
	int	i;
	
	var = v;
	i = 0;
	sem_wait(var->philos[0].sem->dead);
	while (i < var->phil_nb)
	{
		kill(var->pid[i], SIGKILL);
		i++;
	}
	return (NULL);
}

int	check_end(t_philo *p)
{
	sem_wait(p->sem->end);
	if (p->meals == p->var->nmeals)
	{
		sem_post(p->sem->finish);
		sem_post(p->sem->end);
		return (1);
	}
	sem_post(p->sem->end);
	return (0);
}

void	destroy(t_var *var)
{
	sem_close(var->philos->sem->end);
	sem_close(var->philos->sem->print);
	sem_close(var->philos->sem->forks);
	sem_close(var->philos->sem->dead);
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
			sem_post(p->sem->end);
			sem_post(p->sem->dead);
			return (NULL);
		}
		sem_post(p->sem->end);
		// if (check_end(p) == 1)
		// {
		// 	return (NULL);
		// }
		usleep(5000);
	}
}
