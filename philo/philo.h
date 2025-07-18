/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:31:15 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/18 16:27:33 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

//parssing errors;
# define NIGATIVE "eroor : NIGATIVE\n"
# define MAX_INT "eroor : MAX_INT\n"
# define NOT_DIGIT "eroor : NOT_DIGIT\n"
# define TIME_ERROR "eroor : TIME_ERROR\n"
// message philos
# define FORK "has taking a fork;\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIED "died\n"

typedef struct s_table	t_table;

typedef struct s_mutex
{
	pthread_mutex_t	print;
	pthread_mutex_t	meal;
	pthread_mutex_t	end;

}	t_mutex;

typedef struct s_philo
{
	int				id;
	long			last_tm_eat;
	int				count_m;
	long			time_stat;
	bool			full;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t		tread;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				nb_philo;
	long			tm_die;
	long			tm_eat;
	long			tm_sleep;
	int				nb_meals;
	bool			end;
	pthread_mutex_t	*forks;
	t_philo			*p;
	t_mutex			*mtx;
}	t_table;

//time
long	get_time(void);
//parssing
bool	parssing(t_table *table, char **av);
//data init
bool	table_init(t_table *table);
//simulation
bool	simulation(t_table *table);
bool	check_if_die(t_table *table);

//utils
void	print_t(t_philo *philo, char *str);
bool	die(t_table *table);
void	smart_sleep(long time, t_table *table);
bool	check_if_die(t_table *table);

//leaks
void	free_forks(t_table *table);
void	cleaned(t_table *tabl);
void	free_mutex(t_table *table);

#endif