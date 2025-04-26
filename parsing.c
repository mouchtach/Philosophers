/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:53:35 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/26 15:53:42 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void error_exit(char *str)
{
    printf("%s\n", str);
    exit(1);
}  
static char    *valid_input(char *str)
{
    int i = 0;
    while((str[i] >= 9 && str[i] <= 13 ) || (str[i] == 32))
        i++;
    if(str[i] == '+')
        i++;
    else if(str[i] == '-')
        error_exit("negative value xxxxx");
    if(str[i] >= '0' && str[i] <= '9')
        return (str + i); 
    else
        error_exit("note digit");
    return (NULL);
}
static long    ft_atoi(char *str)
{   
    long num;
    int i = 0;

    num = 0;
    str = valid_input(str);
    while(str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + (str[i] - 48);
        if(num > INT_MAX)
            error_exit("int max");
        i++;
    }
    return (num);
}
void    parsing_input(t_table *table, char **argv)
{
    table->philo_number = ft_atoi(argv[1]); //ms >> micro 
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    if(table->time_to_die < 60|| table->time_to_eat < 60 || table->time_to_sleep < 60)
        error_exit("error in value < 60ms");
    if(argv[5])
        table->nbr_limit_meals = ft_atoi(argv[5]);
    else
        table->nbr_limit_meals = -1;
}