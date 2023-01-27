/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:19:59 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/27 10:44:59 by tgrasset         ###   ########.fr       */
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
	var->all_eaten = 0;
	if (av[5] != NULL)
		var->nmeals = ft_atol(av[5]);
	else
		var->nmeals = -1;
}

int	start_processes(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->phil_nb)
	{
		var->pid[i] = fork();
		if (var->pid[i] < 0)
			return (-1);	
		else if (var->pid[i] == 0)
		{
			routine(&var->philos[i]);
			destroy(var);
			exit (0);
		}
		i++;
	}
	return (0);
}

void	init_philos(t_sem *sem, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->phil_nb)
	{
		var->philos[i].n = i + 1;
		var->philos[i].meals = 0;
		var->philos[i].var = var;
		var->philos[i].sem = sem;
		var->philos[i].last_meal = get_time();
		i++;
	}
}

int	init_sem(t_var *var)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/end");
	sem_unlink("/dead");
	sem_unlink("/finish");
	var->philos->sem->forks = sem_open("/forks", O_CREAT, S_IRWXU, var->phil_nb);
	var->philos->sem->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	var->philos->sem->end = sem_open("/end", O_CREAT, S_IRWXU, 1);
	var->philos->sem->dead = sem_open("/dead", O_CREAT, S_IRWXU, 0);
	var->philos->sem->finish = sem_open("/finish", O_CREAT, S_IRWXU, var->phil_nb);
	if (var->philos->sem->forks == SEM_FAILED || var->philos->sem->print == SEM_FAILED
		|| var->philos->sem->end == SEM_FAILED || var->philos->sem->dead == SEM_FAILED || var->philos->sem->finish == SEM_FAILED)
		return (-1);
	return (0);
}
