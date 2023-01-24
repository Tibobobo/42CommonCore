/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:36:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/24 12:31:59 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->mutex->end);
	if (p->var->dead == 0 && p->var->finish != p->var->phil_nb)
	{
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld #%u ", get_time() - p->var->start, p->n);
		printf("%s", msg);
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

void    ft_sleep(long long int time, t_philo *p)
{
    long long int    i;

    i = get_time();
	(void)p;
    while (get_time() - i < time)
	{
		usleep(50);
		check_death(p);
	}
}