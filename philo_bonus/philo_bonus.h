/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:17:48 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/19 21:32:06 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>

// Error messages
# define NEGATIVE "Error: Negative number\n"
# define MAX_INT "Error: Number exceeds INT_MAX\n"
# define NOT_DIGIT "Error: Non-digit character\n"
# define ARG_COUNT "Error: Invalid number of arguments\n"
# define SEMA_ERROR "Error: Semaphore failed\n"
# define MALLOC_ERROR "Error: Malloc failed\n"

// Philosopher actions
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIED "died\n"

typedef struct s_table {
    int     nb_philo;
    long    tm_die;
    long    tm_eat;
    long    tm_sleep;
    int     nb_meals;
    long    start_time;
    pid_t   *pid;
    sem_t   *forks;
    sem_t   *print;
    sem_t   *death;
} t_table;

// Function prototypes
long    get_time(void);
bool    parsing(t_table *, char **);
bool    init_table(t_table *table);
void    cleanup(t_table *table);
void    kill_philos(t_table *table, int count);
void    print_action(int id, t_table *table, char *action);
void    philosopher(int id, t_table *table);
bool    start_simulation(t_table *table);

#endif