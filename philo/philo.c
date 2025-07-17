/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:33:26 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/17 21:36:59 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	t_mutex	mutx;

	table.mtx = &mutx;
	// system("leaks -q philo");
	if (ac == 5 || 6 == ac)
	{
		if (!parssing(&table, av))
			return (1);
		if (!table_init(&table))
			return (1);
		if (!simulation(&table))
			return (cleaned(&table), 1);
			// return (1);
		cleaned(&table);
	}
	else
		printf("eroor : invalid number of arguments\n");
}
