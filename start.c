/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:53:49 by ymouchta          #+#    #+#             */
/*   Updated: 2025/05/01 10:30:02 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void    print_philo(char *str, t_philo *philo)
{
    printf("%ld %d %s\n" , get_time() - philo->last_meal_time , philo->id, str);

}
long    get_time()
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    retrun ((time.tv_sec * 1000) + (time.tv_usec / 1000)); 
}


void   *checking(void *u)
{
    t_table  *table;
    int i = 0;
    table = (t_table *)u;
    while(i < table->philo_number)
    {
        pthread_mutex_lock(&table->mtx.m_eat_c);
        if(get_time() - table->philos[i].last_meal_time >= table->time_to_die)
        {
            pthread_mutex_unlock(&table->mtx.m_eat_c);
            print_philo("died", &table->philos[i]);
            pthread_mutex_lock(&table->mtx.m_end);
            table->end_simulation = true; 
            pthread_mutex_unlock(&table->mtx.m_end);
            break;
        }
        pthread_mutex_unlock(&table->mtx.m_eat_c);
        i++;
    }
    i = 0;
    while(i < table->philo_number)
    {
        if(table->philos[i].meals_counter == table->nbr_limit_meals)
        {
            pthread_mutex_lock(&table->mtx.m_full);
            table->philos[i].full = true;
            pthread_mutex_unlock(&table->mtx.m_full);
        }
    }
    
    return;
}
bool    dinner_start(t_table *table)
{
    pthread_t   monitor;
    pthread_create(&monitor, NULL, checking , table);


    
    
    
}