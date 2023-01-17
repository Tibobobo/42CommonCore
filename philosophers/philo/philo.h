/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:34 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/17 17:06:57 by tgrasset         ###   ########.fr       */
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
    unsigned int    phil_nb;
    unsigned int    ttd;
    unsigned int    tte;
    unsigned int    tts;
    int             nmeals;
    pthread_t       *threads;
    struct timeval  tv;
	long long int   start;
}               t_var;

typedef struct s_philo
{
    t_var   *var;
    unsigned int    n;
    unsigned int    dead;
    unsigned int    meals;
    unsigned int    left;
    unsigned int    right;
}               t_philo;

#endif
