#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <stdbool.h>

typedef  pthread_mutex_t t_mtx;

typedef struct s_fork
{
    t_mtx   fork;
    // int     fork_id;
}   t_fork;

typedef struct s_philo
{
    int         id;
    long        meals_counter;
    bool        full;
    long        last_meal_time;
    t_fork      *left_fork;
    t_fork      *right_fork;
    pthread_t    thread_id;
}t_philo;

typedef struct s_mutx
{
    t_mtx print;
    t_mtx end;
    t_mtx eat_c;
}   t_mutx;

typedef struct s_table
{
    long    philo_number;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    nbr_limit_meals;
    long    start_simulation;
    bool    end_simulation;
    t_fork  *forks;
    t_mutx  mtx;
    t_philo *philos;
}t_table;


void    parsing_input(t_table *table, char **argv);
bool    datat_init(t_table *table);
bool    dinner_start(t_table *table);
#endif
