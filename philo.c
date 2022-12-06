/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:57:44 by afonso            #+#    #+#             */
/*   Updated: 2022/12/06 18:30:58 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

int	main(int argc, char **argv)
{
	long int	*arg_array;
	t_data		data;
	t_time		time;
	t_philo		*philo_array;
	pthread_t	*pthreads;

	arg_array = 0;
	pthreads = 0;
	if (!check_input(argc, argv, &arg_array))
		return (1);
	initialize_datastruct(&data, arg_array, argc);
	initialize_timestruct(&time, arg_array);
	philo_array = load_philos(&data, &time);
	pthreads = load_pthreads(philo_array, data.num_of_philo);
	threads_join(pthreads, &data);
	free_assets(philo_array, arg_array, pthreads);
	return (0);
}
