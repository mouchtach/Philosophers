/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:14:52 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/17 10:15:40 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_t(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->mtx->print);
	if (!check_if_die(philo->table))
		printf("%ld %d %s\n", get_time() - philo->time_stat, philo->id, str);
	pthread_mutex_unlock(&philo->table->mtx->print);
}

bool	die(t_table *table)
{
	pthread_mutex_lock(&table->mtx->end);
	table->end = true;
	pthread_mutex_unlock(&table->mtx->end);
	return (false);
}

void	smart_sleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		usleep(100);
	}
}

bool	check_if_die(t_table *table)
{
	pthread_mutex_lock(&table->mtx->end);
	if (table->end)
	{
		pthread_mutex_unlock(&table->mtx->end);
		return (true);
	}
	pthread_mutex_unlock(&table->mtx->end);
	return (false);
}