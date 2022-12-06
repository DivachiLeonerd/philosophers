/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:23:49 by afonso            #+#    #+#             */
/*   Updated: 2022/12/06 17:04:56 by afonso           ###   ########.fr       */
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
		printf("%lu %d died\n", get_time() - philo->time->start, philo->id);
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
		ft_msleep(philo, philo->time->to_die);
		printf("%ums:Philosopher 1 died\n", philo->time->to_die);
		return (NULL);
	}
	if (philo->id == 1 && philo->data->num_of_philo % 2)
		ft_msleep(philo, philo->time->to_eat + philo->time->to_sleep - 200);
	while (1)
	{
		if (looking2eat(philo))
		{
			if (update_meals_eaten(philo))
				return (NULL);
			if (!print_log(philo, ASLEEP))
				return (NULL);
			ft_msleep(philo, philo->time->to_sleep);
			if (!print_log(philo, THINKING))
				return (NULL);
			ft_msleep(philo, 10);
		}
		else
			return (NULL);
	}
	return (NULL);
}
