/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:24:33 by ymouchta          #+#    #+#             */
/*   Updated: 2025/05/03 20:44:53 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    mutex_init(t_table *table)
{
    if(pthread_mutex_init(&table->mtx->end, NULL) != 0)
        return(false);
    if(pthread_mutex_init(&table->mtx->print, NULL) != 0)
        return(false);    
    if(pthread_mutex_init(&table->mtx->meal, NULL) != 0)
        return(false);
    return (true);
}

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

    i = 0;
    if(!aloccated_forks(table))
        return(false);
    table->p = malloc(sizeof(t_philo) * table->nb_philo);
    if(!table->p)
        return (false);
    while(i < table->nb_philo)
    {
        table->p[i].id = i + 1;
        if(i == 0)
            table->p[i].r_fork = &table->forks[table->nb_philo - 1];
        else
            table->p[i].r_fork = &table->forks[i];
        table->p[i].l_fork = &table->forks[i - 1];
        table->p[i].count_m = 0;
        table->p[i].full = false;
        table->p[i].table = table;
        table->p[i].time_stat = get_time();
        table->p[i].last_tm_eat = get_time();
        i++;
    }
    table->end = false;
 
    if(!mutex_init(table))
        return(false);
    return (true);
}
