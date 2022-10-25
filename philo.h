/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:02:53 by afonso            #+#    #+#             */
/*   Updated: 2022/10/25 21:15:12 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define EATING 0;
# define ASLEEP 1;
# define THINKING 2;
# define DEAD 3;

typedef struct s_fork
{
	int	lasttime_used;
	int	is_locked;// This is a measure to reduce downtime between locking/unlocking.
					//  note: This is mostly important when mutex is locked (is_locked == 1). If it is 0 then philo will have to use pthread_mutex_lock()
	pthread_mutex_t flock;
}t_fork;

typedef struct s_philo
{
	int		id;
	int		lastmeal_time; // might be useless after thorough analysis. note: this is supposed to be compared against t_fork's lasttime_used
	int		times_eaten; //for the purposes of ending the simulation
	int		philo_state; //as in: eating, sleeping, thinking
	t_fork	right_fork;
	t_fork	*left_fork;
}t_philo;

void	checkif_number(char **argv, int *ret_address, int i, int *j);
int		is_integer(void *x);


#endif
