/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:42 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/25 15:06:00 by tgrasset         ###   ########.fr       */
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

void	release_forks(t_philo *p)
{
	print(p, "is sleeping\n");
	sem_post(p->sem->forks);
	sem_post(p->sem->forks);
	ft_sleep(p->var->tts, p);
}

void	eat(t_philo *p)
{
	print(p, "is eating\n");
	p->last_meal = get_time();
	ft_sleep(p->var->tte, p);
	p->meals++;
}

int	routine(t_philo *p)
{
	if (p->var->nmeals == 0)
		return (0);
	pthread_create(&p->t, NULL, &check_death, p);
	pthread_detach(p->t);
	if (p->n % 2 == 0)
		usleep(p->var->tte * 1000);
	while (1)
	{
		get_forks(p);
		eat(p);
		release_forks(p);
		print(p, "is thinking\n");
		if (check_end(p) == 1)
			break ;
	}
	return (0);
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
	if (start_processes(&var) == -1)
		return (ft_error(4, &var));
	i = 0;
	while (i < var.phil_nb)
	{
		waitpid(var.pid[i], NULL, 0);
		i++;
	}
	destroy(&var);
	return (0);
}
