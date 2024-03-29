/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:42 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/01 09:34:24 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(t_philo *p)
{
	sem_wait(p->sem->forks);
	print(p, "has taken a fork\n");
	sem_wait(p->sem->forks);
	print(p, "has taken a fork\n");
}

void	eat(t_philo *p)
{
	print(p, "is eating\n");
	sem_wait(p->sem->variables);
	p->last_meal = get_time();
	p->meals++;
	sem_post(p->sem->variables);
	ft_sleep(p->var->tte, p);
}

void	release_forks(t_philo *p)
{
	print(p, "is sleeping\n");
	if (check_end(p) == 1)
		sem_post(p->sem->finish);
	sem_post(p->sem->forks);
	sem_post(p->sem->forks);
	ft_sleep(p->var->tts, p);
}

int	routine(t_philo *p)
{
	if (p->var->nmeals == 0)
		return (0);
	sem_wait(p->sem->finish);
	if (pthread_create(&p->t, NULL, &check_death, p) != 0)
		return (-1);
	pthread_detach(p->t);
	if (p->n % 2 == 0)
		usleep(p->var->tte * 1000);
	while (1)
	{
		get_forks(p);
		eat(p);
		release_forks(p);
		print(p, "is thinking\n");
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	t_var	var;
	t_sem	sem;
	int		i;

	if (ac > 6 || ac < 5 || valid_args(av) == 0)
		return (ft_error(1, &var));
	if (ft_atol(av[1]) < 1)
		return (write(2, "Error\nSimulation needs at least 1 philo\n", 40), -1);
	init_var(&var, av);
	init_philos(&sem, &var);
	if (init_sem(&var) == -1)
		return (ft_error(3, &var));
	var.start = get_time();
	i = start_processes(&var);
	if (i != 0)
	{
		kill_processes(&var, i);
		destroy(&var);
		return (ft_error(4, &var));
	}
	i = 0;
	usleep(var.tte * 1000 + 5000);
	wait_and_kill(&var);
	destroy(&var);
	return (0);
}
