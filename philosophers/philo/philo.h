/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:34 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/20 19:02:43 by tgrasset         ###   ########.fr       */
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
char	*ft_litoa(long long int nb);
char	*ft_strjoin(char *s1, char *s2);
int ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long long int nb, int fd);

#endif
