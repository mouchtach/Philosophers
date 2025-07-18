/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:39:14 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/18 16:54:58 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(char *av)
{
	int		i;
	long	num;

	num = 0;
	i = 0;
	while ((av[i] >= 9 && av[i] <= 13) || (av[i] == 32))
		i++;
	if (av[i] == '+')
		i++;
	if (av[i] == '-')
		return (printf(NIGATIVE), -1);
	if (!(av[i] >= '0' && av[i] <= '9'))
		return (printf(NOT_DIGIT), -1);
	while (av[i] >= '0' && av[i] <= '9')
	{
		num = (num * 10) + (av[i] - 48);
		if (num > INT_MAX)
			return (printf(MAX_INT), -1);
		i++;
	}
	return (num);
}

bool	parssing(t_table *table, char **av)
{
	if (av[5])
	{
		table->nb_meals = ft_atoi(av[5]);
		if (table->nb_meals <= 0)
			return (false);
	}
	else
		table->nb_meals = -1;
	table->nb_philo = ft_atoi(av[1]);
	table->tm_die = ft_atoi(av[2]);
	table->tm_eat = ft_atoi(av[3]);
	table->tm_sleep = ft_atoi(av[4]);
	if (table->nb_philo == -1 || table->tm_die == -1 || table->tm_eat == -1
		|| table->tm_sleep == -1)
		return (false);
	return (true);
}
