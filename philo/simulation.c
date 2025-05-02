/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:40:16 by ymouchta          #+#    #+#             */
/*   Updated: 2025/05/02 16:13:20 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    monitor(t_table *table)
{

}

bool    simulation(t_table *table)
{

    pthread_t   mntr;
    
    pthread_create(&mntr, NULL, &monitor, table);


    
    
}