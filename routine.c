/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:23:49 by afonso            #+#    #+#             */
/*   Updated: 2022/12/02 14:43:58 by afonso           ###   ########.fr       */
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

static void	update_philo_state(t_philo *philo)
{
	if (philo->state == ASLEEP)
	{
		if (!check_me_tummy(philo))
		{
			print_log(philo, ASLEEP);
			ft_msleep(philo->time->to_sleep);
			philo->state = THINKING;
			if (!check_me_tummy(philo))
				print_log(philo, THINKING);
		}
	}
	else if (philo->state == THINKING && looking_to_eat(philo))
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
	if (isphilo_even(philo))
		ft_msleep(10);
	// print_log(philo, 200);
	while (!check_me_tummy(philo))
	{
		update_philo_state(philo);
		// if (update_meals_eaten(philo))
		// 	break ;
		if (philo->times_eaten == philo->data->num_of_meals)
			break ;
	}
	return (NULL);
}
