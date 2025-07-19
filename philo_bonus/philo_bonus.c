/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:01:50 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/19 21:29:05 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac, char **av)
{
    t_table table;

    if (ac == 5 || ac == 6)
	{
    	if (!parsing(&table, av))
        	return 1;
    	if (!init_table(&table))
        	return 1;
    	if (!start_simulation(&table))
		{
        	cleanup(&table);
        	return 1;
    	}
	}
	else
	{
		printf(ARG_COUNT);
		return 1;
	}
    cleanup(&table);
    return 0;
}
