/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:59:19 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/19 21:36:11 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void print_action(int id, t_table *table, char *action)
{
    sem_wait(table->print);
    printf("%ld %d %s", get_time() - table->start_time, id, action);
    sem_post(table->print);
}

void philosopher(int id, t_table *table)
{
    int meals = 0;
    long last_meal = get_time();

    while (1)
	{
        print_action(id, table, THINK);
        sem_wait(table->forks);
        print_action(id, table, FORK);
        sem_wait(table->forks);
        print_action(id, table, FORK);
        print_action(id, table, EAT);
        last_meal = get_time();
        usleep(table->tm_eat * 1000);
        meals++;
        sem_post(table->forks);
        sem_post(table->forks);
        if (table->nb_meals != -1 && meals >= table->nb_meals)
            break;
        print_action(id, table, SLEEP);
        usleep(table->tm_sleep * 1000);
        if (get_time() - last_meal > table->tm_die)
		{
            sem_wait(table->print);
            printf("%ld %d %s", get_time() - table->start_time, id, DIED);
            exit(1);
        }
    }
    exit(0);
}

bool start_simulation(t_table *table)
{
    int i = 0;
    int status;

    while (i < table->nb_philo)
	{
        table->pid[i] = fork();
        if (table->pid[i] < 0)
		{
            kill_philos(table, i);
            return false;
        }
        if (table->pid[i] == 0)
		{
            philosopher(i + 1, table);
        }
        i++;
    }
    while (waitpid(-1, &status, 0) > 0) {
        if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
            kill_philos(table, table->nb_philo);
            break;
        }
    }

    return true;
}