/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:12:48 by afonso            #+#    #+#             */
/*   Updated: 2022/12/05 12:36:02 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_datastruct(t_data *data, long *arg_array, int argc)
{
	if (argc == 6)
		data->num_of_meals = arg_array[4];
	else
		data->num_of_meals = -1;
	data->is_dead = 0;
	data->num_of_philo = (unsigned int)arg_array[0];
	pthread_mutex_init(&(data->data_lock), NULL);
	pthread_mutex_init(&(data->print), NULL);
	return ;
}

void	initialize_timestruct(t_time *time, long *arg_array)
{
	// time->start = get_time();
	time->to_die = arg_array[1];
	time->to_eat = arg_array[2];
	time->to_sleep = arg_array[3];
}
