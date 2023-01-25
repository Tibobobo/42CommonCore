/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:36:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/25 11:42:54 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *p, char *msg)
{
	sem_wait(p->sem->end);
	if (p->var->dead == 0 && p->var->finish != p->var->phil_nb)
	{
		sem_wait(p->sem->print);
		printf("%lld #%u %s", get_time() - p->var->start, p->n, msg);
		sem_post(p->sem->print);
	}
	sem_post(p->sem->end);
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
	}
}
