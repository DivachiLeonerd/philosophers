/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:53:47 by afonso            #+#    #+#             */
/*   Updated: 2022/10/25 18:04:41 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct mystruct
{
    int             i;
    pthread_mutex_t lock;
};

void    *IMGAY(void *arg)
{
    struct mystruct *mystruct;
    int             i;

    i = 0;
    mystruct = (struct mystruct *)arg;
    while (i < 4)
    {
        pthread_mutex_lock(&(mystruct->lock));
        printf("I can't believe this!! I'm Gay:mystruct.%d\n", (mystruct->i)--);
        i++;
        pthread_mutex_unlock(&(mystruct->lock));
    }
}

void    *counting(struct mystruct *mystruct)
{
    int i;

    i = 0;
    while (i < 4)
    {
        pthread_mutex_lock(&(mystruct->lock));
        printf("counting:mystruct.i = %d\n", (mystruct->i)++);
        pthread_mutex_unlock(&(mystruct->lock));
        i++;
    }
}

void	main(void)
{
    pthread_t       new_thread;
    struct mystruct mystruct;
    
    mystruct.i = 0;
    pthread_mutex_init(&(mystruct.lock), NULL);
    pthread_create(&new_thread, NULL, IMGAY, &(mystruct.i));
    counting(&mystruct);
    pthread_join(new_thread, NULL);
    pthread_mutex_destroy(&(mystruct.lock));

    //allocate memory resources: A.K.A. all philos and an array of forks
    //The array of forks should tell us if forks in positions n and n-1 are available to use



    //make a function that checks if a philosopher can eat with both forks



    //make a function where a philo knows which forks around him have been used recently


    //make a function that compares each philos time until starvation and how long ago have the forks around him been used

    // if a philo knows one fork has been used recently he can reserve it and wait for the second fork to be available
}