/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:34 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/24 12:32:07 by tgrasset         ###   ########.fr       */
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

typedef struct s_var
{
    int             phil_nb;
    int             ttd;
    int             tte;
    int             tts;
    int             nmeals;
    int             *forks;
    int             dead;
    int             finish;
    pthread_t       *threads;
	long long int   start;
    struct s_philo  *philos;
}               t_var;

typedef struct s_mutex
{
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    pthread_mutex_t end;
}               t_mutex;

typedef struct s_philo
{
    t_var   *var;
    t_mutex *mutex;
    int     n;
    int     dead;
    long long int   last_meal;
    int     meals;
}               t_philo;

int             ft_error(int n, t_var *var);
int             valid_args(char **av);
long long int	ft_atol(const char *nptr);
int ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
void	destroy_and_free(t_var *var);
void    init_var(t_var *var, char **av);
void    start_threads(t_var *var);
void	init_philos(t_mutex *mut, t_var *var);
int	init_mutex(t_var *var);
void	*routine(void *philo);
long long int	get_time(void);
void    ft_sleep(long long int time, t_philo *p);
void	join_threads(t_var *var);
void	destroy_and_free(t_var *var);
void	check_death(t_philo *p);
int		check_end(t_philo *p);
void	kill_lonely_philo(t_philo *p);
void	print(t_philo *p, char *msg);

#endif
