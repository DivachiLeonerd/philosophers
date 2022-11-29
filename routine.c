/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:23:49 by afonso            #+#    #+#             */
/*   Updated: 2022/11/29 16:30:02 by afonso           ###   ########.fr       */
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
	else if ((get_time() - philo->last_meal) >= philo->time->to_die)
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
	pthread_mutex_lock(&(philo->data->data_lock));
	if (philo->times_eaten == philo->data->num_of_meals)
	{
		philo->data->how_many_finished++;
		pthread_mutex_unlock(&(philo->data->data_lock));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->data_lock));
	return (0);
}

static void	update_philo_state(t_philo *philo)
{
	if (philo->state == ASLEEP)
	{
		print_log(philo, ASLEEP);
		ft_msleep(philo->time->to_sleep);
		philo->state = THINKING;
	}
	else if (philo->state == THINKING && looking2eat(philo))
		philo->state = EATING;
	if (philo->state == EATING)
	{
		philo->last_meal = get_time();
		ft_msleep(philo->time->to_eat);
		pthread_mutex_lock(&(philo->right_fork.flock));
		philo->right_fork.is_locked = 0;
		pthread_mutex_unlock(&(philo->right_fork.flock));
		pthread_mutex_lock(&(philo->left_fork->flock));
		philo->left_fork->is_locked = 0;
		pthread_mutex_unlock(&(philo->left_fork->flock));
		philo->state = ASLEEP;
	}
	return ;
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *) philosopher;
	while (1)
	{
		if (check_me_tummy(philo))
			break ;
		update_philo_state(philo);
		if (update_meals_eaten(philo))
			break ;
		pthread_mutex_lock(&(philo->data->data_lock));
		if (philo->data->how_many_finished == philo->data->num_of_philo)
		{
			pthread_mutex_unlock(&(philo->data->data_lock));
			break ;
		}
		pthread_mutex_unlock(&(philo->data->data_lock));
	}
	return (NULL);
}
