/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:15:29 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/17 21:36:47 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

void	cleaned(t_table *table)
{
	if(table->p)
	{
		free(table->p);
	}
	free_forks(table);
	free_mutex(table);
}

void	free_forks(t_table *table)
{
	int	i;

	i = 0;
	if (table->forks)
	{
		while (i < table->nb_philo)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
		table->forks = NULL;
	}
}

void	free_mutex(t_table *table)
{
	pthread_mutex_destroy(&table->mtx->end);
	pthread_mutex_destroy(&table->mtx->print);
	pthread_mutex_destroy(&table->mtx->meal);
}

