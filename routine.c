/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:23:49 by afonso            #+#    #+#             */
/*   Updated: 2022/12/05 19:05:24 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_me_tummy(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->data_lock));
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&(philo->data->data_lock));
		return (1);
	}
	if (get_time() - philo->last_meal > philo->time->to_die)
	{
		philo->data->is_dead = 1;
		print_log(philo, DEAD);
		pthread_mutex_unlock(&(philo->data->data_lock));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->data_lock));
	return (0);
}

static int	update_meals_eaten(t_philo *philo)
{
	if (philo->times_eaten == philo->data->num_of_meals)
		return (1);
	return (0);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *) philosopher;
	philo->last_meal = philo->time->start;
	//printf("start:%lu\n", get_time() - philo->time->start);
	//printf("start2: %lu\n", get_time() - philo->time->start);
	if (philo->data->num_of_philo == 1)
	{
		printf("0ms:Philosopher 1 has taken a fork\n");
		ft_msleep(philo->time->to_die);
		printf("%ums:Philosopher 1 died\n", philo->time->to_die);
		return (NULL);
	}
	while (1)
	{
		
		if (looking2eat(philo))
		{
			if (update_meals_eaten(philo))
				return (NULL);
			if (!check_me_tummy(philo))
				print_log(philo, ASLEEP);
			else
				return (NULL);
			ft_msleep(philo->time->to_sleep);
			if (!check_me_tummy(philo))
				print_log(philo, THINKING);
			else
				return (NULL);
		}
		else
			return (NULL);
	}
	return (NULL);
}
