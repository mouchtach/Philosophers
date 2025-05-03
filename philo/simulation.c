/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:40:16 by ymouchta          #+#    #+#             */
/*   Updated: 2025/05/03 20:47:09 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void    print_t(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->table->mtx->print);
    printf("%ld %d %s\n", get_time() - philo->time_stat, philo->id, str);
    pthread_mutex_unlock(&philo->table->mtx->print);
}

bool    check(t_table *table)
{
    int i;

    i = 0;
    pthread_mutex_lock(&table->mtx->meal);
    while(i < table->nb_philo && table->p[i].count_m == table->nb_meals) // 0 1 2 / 3
        i++;
    pthread_mutex_unlock(&table->mtx->meal);
    if(i == table->nb_philo)
    {
        pthread_mutex_lock(&table->mtx->end);
        table->end = true;
        pthread_mutex_unlock(&table->mtx->end);
        return (false);
    }
    i = 0;
    while(i < table->nb_philo)
    {
        if(get_time() - table->p[i].last_tm_eat >= table->tm_die)
        {
            print_t(&table->p[i], "died");
            pthread_mutex_lock(&table->mtx->end);
            table->end = true;
            pthread_mutex_unlock(&table->mtx->end);
            return (false);
        }
        i++;
    }
    return (true);
}

void    *monitor(void *data)
{
    t_table *table = (t_table *) data; 
    while(1)
    {
        if(!check(table))
            break;
    }
    return (NULL);

}

void    *routine(void *data)
{

    t_philo *philo =(t_philo *) data;
    
    if(philo->id % 2 == 0)
        usleep(1000);
    pthread_mutex_lock(&philo->table->mtx->end);
    while (!philo->table->end)
    {
        pthread_mutex_unlock(&philo->table->mtx->end);
        print_t(philo, "is thinkng");
        pthread_mutex_lock(philo->r_fork);
        print_t(philo, "has taken a fork");
        pthread_mutex_lock(philo->l_fork);
        print_t(philo, "has taken a fork");
        print_t(philo, "is eating");
        pthread_mutex_lock(&philo->table->mtx->meal);
        philo->count_m++;
        philo->last_tm_eat = get_time();
        pthread_mutex_unlock(&philo->table->mtx->meal);
        usleep(philo->table->tm_eat);
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
        print_t(philo, "is sleeping");
        usleep(philo->table->tm_sleep);
        pthread_mutex_lock(&philo->table->mtx->end);
    }
    return NULL;
}

bool    simulation(t_table *table)
{

    pthread_t   mntr;
    int i;

    i  = 0;
    pthread_create(&mntr, NULL, &monitor, table);
    while(i < table->nb_philo)
    {
        if (pthread_create(&table->p[i].tread, NULL,&routine, &table->p[i]) != 0)
            return(false);
        i++;
    }
    if(pthread_join(mntr, NULL) != 0)
        return(false);
    i = 0;
    while(i < table->nb_philo)
    {
        if (pthread_join(table->p[i].tread, NULL) != 0)
            return(false);
        i++;
    }
    return (true);
}