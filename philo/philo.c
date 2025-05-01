/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:33:26 by ymouchta          #+#    #+#             */
/*   Updated: 2025/05/01 11:23:42 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_table table;
    
    if(ac == 5 || 6 == ac)
    {
        if(!parssing(&table, av))
            return (1);
        if(!table_init(&table))
            return (1);

    }


}