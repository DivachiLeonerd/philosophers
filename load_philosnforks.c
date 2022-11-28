/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_philosnforks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:41:01 by afonso            #+#    #+#             */
/*   Updated: 2022/11/28 16:15:51 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo(t_philo *philo, int numof_philo,
		t_data *data, t_time *time)
{
	philo->id = numof_philo;
	philo->times_eaten = 0;
	philo->last_meal = get_time();
	philo->state = THINKING;
	philo->right_fork.is_locked = 0;
	philo->data = data;
	philo->time = time;
	pthread_mutex_init(&(philo->right_fork.flock), NULL);
}

static void	set_leftforks(t_philo *philo, unsigned int numof_philo,
		unsigned int total_philo, t_philo *array)
{
	if (numof_philo != total_philo - 1)
		philo->left_fork = &(array[numof_philo + 1].right_fork);
	else
		philo->left_fork = &(array[0].right_fork);
	philo->right_fork.last_time_used = philo->time->start;
	return ;
}

t_philo	*load_philos(t_data *data, t_time *time)
{
	int				temp;
	t_philo			*philo_array;
	unsigned int	aux;

	aux = 0;
	temp = (data->num_of_philo - 1);
	philo_array = malloc(data->num_of_philo * sizeof(t_philo));
	while (temp > -1)
	{
		set_philo(&(philo_array[temp]), temp + 1, data, time);
		temp--;
	}
	while (aux < data->num_of_philo)
	{
		set_leftforks(&(philo_array[aux]), aux, data->num_of_philo,
			philo_array);
		aux++;
	}
	return (philo_array);
}

pthread_t	*load_pthreads(t_philo *philo_array, int numof_philo)
{
	pthread_t	*pthreads;

	pthreads = malloc(numof_philo * sizeof(pthread_t));
	numof_philo--;
	while (numof_philo > -1)
	{
		pthread_create(&(pthreads[numof_philo]), 0, routine,
			(void *)(&philo_array[numof_philo]));
		numof_philo--;
	}
	return (pthreads);
}
