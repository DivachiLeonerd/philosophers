/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:53:47 by afonso            #+#    #+#             */
/*   Updated: 2022/11/25 11:01:34 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
    long int    *arg_array;
    t_data      data;
    t_time      time;
    t_philo     *philo_array;
    pthread_t   *pthreads;
    
    arg_array = 0;
    pthreads = 0;
    //allocate memory resources: A.K.A. all philos and an array of forks
    //The array of forks should tell us if forks in positions n and n-1 are available to use
    if (!check_input(argc, argv, &arg_array))
        return (1);
    initialize_datastruct(&data, arg_array, argc);
    initialize_timestruct(&time, arg_array);
    philo_array = load_philos(&data, &time);
    pthreads = load_pthreads(philo_array, data.num_of_philo);
    threads_join(pthreads, &data);
    free_assets(philo_array, arg_array, pthreads);
    //make a function that checks if a philosopher can eat with both forks



    //make a function where a philo knows which forks around him have been used recently


    //make a function that compares each philos time until starvation and how long ago have the forks around him been used

    // if a philo knows one fork has been used recently he can reserve it and wait for the second fork to be available
    return (0);
}