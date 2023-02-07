/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:34 by tgrasset          #+#    #+#             */
/*   Updated: 2023/02/01 09:34:54 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef struct s_sem
{
	sem_t	*forks;
	sem_t	*print;
	sem_t	*variables;
	sem_t	*finish;
}				t_sem;

typedef struct s_philo
{
	struct s_var	*var;
	t_sem			*sem;
	int				n;
	long long int	last_meal;
	int				meals;
	pthread_t		t;
}				t_philo;

typedef struct s_var
{
	int				phil_nb;
	int				ttd;
	int				tte;
	int				tts;
	int				nmeals;
	long long int	start;
	t_philo			philos[1024];
	pid_t			pid[1024];
}				t_var;

int				ft_error(int n, t_var *var);
int				valid_args(char **av);
long long int	ft_atol(const char *nptr);
int				ft_strlen(char *str);
void			ft_putstr_fd(char *s, int fd);
void			destroy_and_free(t_var *var);
void			init_var(t_var *var, char **av);
int				start_processes(t_var *var);
void			init_philos(t_sem *sem, t_var *var);
int				init_sem(t_var *var);
int				routine(t_philo *p);
long long int	get_time(void);
void			ft_sleep(long long int time, t_philo *p);
void			destroy(t_var *var);
void			*check_death(void *philo);
int				check_end(t_philo *p);
void			print(t_philo *p, char *msg);
void			wait_and_kill(t_var *var);
void			kill_processes(t_var *var, int i);

#endif
