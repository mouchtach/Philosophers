/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:08:01 by ymouchta          #+#    #+#             */
/*   Updated: 2025/05/02 16:09:19 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    get_time()
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    retrun ((time.tv_sec * 1000) + (time.tv_usec / 1000)); 
}