/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:31:15 by ymouchta          #+#    #+#             */
/*   Updated: 2025/05/02 16:08:46 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <limits.h>
#include <stdbool.h>

//parssing errors;
# define NIGATIVE "eroor : NIGATIVE\n"
# define MAX_INT "eroor : MAX_INT\n"
# define NOT_DIGIT "eroor : NOT_DIGIT\n"
# define TIME_ERROR "eroor : TIME_ERROR\n"

typedef struct s_philo
{
    int             id;
    int             last_tm_eat;
    int             count_m;
    bool            full;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
}   t_philo;

typedef struct s_table
{       
    int             nb_philo;       //number_of_philosophers
    long            tm_die;         //time_to_die
    long            tm_eat;         //time_to_eat
    long            tm_sleep;       //time_to_sleep
    int             nb_meals;      //number_of_times_each_philosopher_must_eat
    bool            end;
    pthread_mutex_t *forks;
    t_philo         *p;
}   t_table;


//parssing
bool    parssing(t_table *table, char **av);
//data init
bool    table_init(t_table *table);
//simulation
bool    simulation(t_table *table);
#endif