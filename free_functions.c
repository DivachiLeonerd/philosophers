/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:08:43 by afonso            #+#    #+#             */
/*   Updated: 2022/11/25 11:02:49 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

static void	free_mutex(t_philo	*philo_array, int numof_philo)
{
	numof_philo--;
	while (numof_philo > - 1)
	{
		pthread_mutex_destroy(&(philo_array[numof_philo].right_fork.flock));
		numof_philo--;
	}
	return ;
}

void	free_assets(t_philo *philo_array, long int *arg_array, pthread_t *pthreads)
{
	free_mutex(philo_array, (philo_array[0]).data->num_of_philo);
	free(philo_array);
	pthread_mutex_destroy(&((philo_array[0]).data->data_lock));
	pthread_mutex_destroy(&((philo_array[0]).data->print));
	free(arg_array);
	free(pthreads);
	return ;
}

void	threads_join(pthread_t *thread_array, t_data *data)
{
	int	variable;

	variable = data->num_of_philo;
	variable--;
	while (variable > -1)
	{
		pthread_join(thread_array[variable], NULL);
		variable--;
	}
}