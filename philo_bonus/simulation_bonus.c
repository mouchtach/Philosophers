/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:59:19 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/20 17:42:43 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_action(int id, t_table *table, char *action)
{
	sem_wait(table->print);
	printf("%ld %d %s", get_time() - table->start_time, id, action);
	sem_post(table->print);
}

void	*monitor_death(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (table->nb_meals > 0 && table->meals_eaten >= table->nb_meals)
			exit(0);
		if (get_time() - table->last_meal > table->tm_die)
		{
			sem_wait(table->print);
			printf("%ld %d %s", get_time() - table->start_time, table->id,
				DIED);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	philosopher(int id, t_table *table)
{
	pthread_t	tread;

	table->meals_eaten = 0;
	table->last_meal = get_time();
	table->id = id;
	pthread_create(&tread, NULL, monitor_death, (void *)table);
	while (1)
	{
		print_action(id, table, THINK);
		sem_wait(table->forks);
		print_action(id, table, FORK);
		sem_wait(table->forks);
		print_action(id, table, FORK);
		print_action(id, table, EAT);
		table->last_meal = get_time();
		usleep(table->tm_eat * 1000);
		table->meals_eaten++;
		sem_post(table->forks);
		sem_post(table->forks);
		print_action(id, table, SLEEP);
		usleep(table->tm_sleep * 1000);
	}
}

bool	start_simulation(t_table *table)
{
	int	i;
	int	status;

	i = 0;
	while (i < table->nb_philo)
	{
		table->pid[i] = fork();
		if (table->pid[i] < 0)
		{
			kill_philos(table, i);
			return (false);
		}
		if (table->pid[i] == 0)
			philosopher(i + 1, table);
		i++;
	}
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			kill_philos(table, table->nb_philo);
			break ;
		}
	}
	return (true);
}
