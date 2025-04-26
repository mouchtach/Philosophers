/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datainit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:07:54 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/26 17:04:14 by ymouchta         ###   ########.fr       */
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
        table->philos->id = i + 1;
        table->philos->full = false;
        if(i == 0)
            table->philos->right_fork = table->philo_number - 1;
        else
            table->philos->right_fork = i;
        table->philos->left_fork = i - 1;
        table->philos->meals_counter = 0;
        i++;
    }
    // if(!set_table(table))
    //     return(false);
    return (true);
}
