/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:33:26 by ymouchta          #+#    #+#             */
/*   Updated: 2025/05/03 20:43:53 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_table table;
    t_mutex   mutx;

    table.mtx = &mutx;

    if(ac == 5 || 6 == ac)
    {
        if(!parssing(&table, av))
            return (1);

        if(!table_init(&table))
            return (1); // free
        if(!simulation(&table))
            return (1); // free   
    }
}