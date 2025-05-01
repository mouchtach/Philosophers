/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:24:33 by ymouchta          #+#    #+#             */
/*   Updated: 2025/05/01 11:45:42 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    aloccated_forks(t_table *table)
{
    int i;

    i = 0;
    table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
    if(!table->forks)
        return(false);
    while(i < table->nb_philo)
    {
        if(pthread_mutex_init(&table->forks[i], NULL))
            return (false);
        i++;
    }
    return (true);
}

bool    table_init(t_table *table)
{
    int i;
    write(1, "Z\n", 2);

    i = 0;
    if(!alocated_fork(table))
        return(false);
    
    
    

}