/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:28:18 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/27 14:02:49 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_and_kill(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->phil_nb)
	{
		sem_wait(var->philos->sem->finish);
		i++;
	}
	i = 0;
	while (i < var->phil_nb)
	{
		kill(var->pid[i], SIGKILL);
		i++;
	}
	i = 0;
	while (i < var->phil_nb)
	{
		waitpid(var->pid[i], NULL, 0);
		i++;
	}
}

int	check_end(t_philo *p)
{
	sem_wait(p->sem->variables);
	if (p->meals == p->var->nmeals)
	{
		sem_post(p->sem->variables);
		return (1);
	}
	sem_post(p->sem->variables);
	return (0);
}

void	destroy(t_var *var)
{
	sem_close(var->philos->sem->variables);
	sem_close(var->philos->sem->print);
	sem_close(var->philos->sem->forks);
	sem_close(var->philos->sem->finish);
}

void	*check_death(void *philo)
{
	long long int	t;
	t_philo			*p;
	int				i;

	i = 0;
	p = philo;
	while (1)
	{
		t = get_time();
		sem_wait(p->sem->variables);
		if (t - p->last_meal > p->var->ttd)
		{
			sem_post(p->sem->variables);
			sem_wait(p->sem->print);
			printf("%lld #%u died\n", t - p->var->start, p->n);
			while (i < p->var->phil_nb)
			{
				sem_post(p->sem->finish);
				i++;
			}
			return (NULL);
		}
		sem_post(p->sem->variables);
		usleep(5000);
	}
}
