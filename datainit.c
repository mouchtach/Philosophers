/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datainit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:07:54 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/30 16:33:24 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// static bool    set_table(t_table *table) 
// {
//     table->end_simulation = 0;
//     table.

    

// }
static bool    aloccated_forks(t_table *table)
{
    table->forks = malloc(sizeof(t_mtx) * table->philo_number);
    if(!table->forks)
        return(false);
    int i = 0;
    while(i < table->philo_number)
    {
        if(pthread_mutex_init(&table->forks[i], NULL))
            return (false);
        i++;
    }
    return (true);
}


bool    datat_init(t_table *table)
{
    if(!aloccated_forks(table))
        return(false);
    table->philos = malloc(sizeof(t_philo) * table->philo_number);
    if(!table->philos)
        return(false);
    int i = 0;
    while(i < table->philo_number)
    {
        table->philos[i].id = i + 1;
        table->philos[i].full = false;
        if(i == 0)
            table->philos[i].right_fork = table->philo_number - 1;
        else
            table->philos[i].right_fork = i;
        table->philos[i].left_fork = i - 1;
        table->philos[i].meals_counter = 0;
        i++;
    }
    table->end_simulation = false;
    return (true);
}
