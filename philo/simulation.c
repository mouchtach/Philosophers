/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:40:16 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/20 17:52:53 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check(t_table *table)
{
	int	i;

	i = 0;
	if (table->nb_meals != -1)
	{
		pthread_mutex_lock(&table->mtx->meal);
		while (i < table->nb_philo && table->p[i].count_m >= table->nb_meals)
			i++;
		pthread_mutex_unlock(&table->mtx->meal);
		if (i == table->nb_philo)
			return (die(table));
	}
	i = 0;
	while (i < table->nb_philo)
	{
		if (get_time() - table->p[i].last_tm_eat >= table->tm_die)
		{
			print_t(&table->p[i], "died");
			return (die(table));
		}
		i++;
	}
	return (true);
}

void	*monitor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		if (!check(table))
			break ;
	}
	return (NULL);
}

bool	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_t(philo, "has taken a fork");
	if (philo->table->nb_philo == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		smart_sleep(philo->table->tm_die, philo->table);
		return (false);
	}
	pthread_mutex_lock(philo->l_fork);
	print_t(philo, "has taken a fork");
	print_t(philo, "is eating");
	pthread_mutex_lock(&philo->table->mtx->meal);
	philo->count_m++;
	philo->last_tm_eat = get_time();
	pthread_mutex_unlock(&philo->table->mtx->meal);
	smart_sleep(philo->table->tm_eat, philo->table);
	return (true);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		smart_sleep(philo->table->tm_eat / 2, philo->table);
	while (!check_if_die(philo->table))
	{
		print_t(philo, "is thinkng");
		if (!eating(philo))
			return (NULL);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		print_t(philo, "is sleeping");
		smart_sleep(philo->table->tm_sleep, philo->table);
	}
	return (NULL);
}

bool	simulation(t_table *table)
{
	pthread_t	mntr;
	int			i;

	i = 0;
	pthread_create(&mntr, NULL, &monitor, table);
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->p[i].tread, NULL, &routine,
				&table->p[i]) != 0)
			return (false);
		i++;
	}
	if (pthread_join(mntr, NULL) != 0)
		return (false);
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->p[i].tread, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}
