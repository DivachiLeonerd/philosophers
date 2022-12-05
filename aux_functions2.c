/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:40:36 by afonso            #+#    #+#             */
/*   Updated: 2022/12/05 19:02:40 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isphilo_even(t_philo *philo)
{
	int	number;

	number = philo->id % 2;
	if (number)
		return (0);
	else
		return (1);
}

static int	even_version(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork.flock));
	if (check_me_tummy(philo))
	{
		pthread_mutex_unlock(&(philo->right_fork.flock));
		return (0);
	}
	print_log(philo, FORK);
	pthread_mutex_lock(&(philo->left_fork->flock));
	if (check_me_tummy(philo))
	{
		pthread_mutex_unlock(&(philo->left_fork->flock));
		pthread_mutex_unlock(&(philo->right_fork.flock));
		return (0);
	}
	print_log(philo, FORK);
	if (check_me_tummy(philo))
	{
		pthread_mutex_unlock(&(philo->left_fork->flock));
		pthread_mutex_unlock(&(philo->right_fork.flock));
		return (0);
	}
	print_log(philo, EATING);
	ft_msleep(philo->time->to_eat);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(philo->left_fork->flock));
	pthread_mutex_unlock(&(philo->right_fork.flock));
	(philo->times_eaten)++;
	return (1);
}

static int	odd_version(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->flock));
	if (check_me_tummy(philo))
	{
		pthread_mutex_unlock(&(philo->left_fork->flock));
		return (0);
	}
	print_log(philo, FORK);
	pthread_mutex_lock(&(philo->right_fork.flock));
	if (check_me_tummy(philo))
	{
		pthread_mutex_unlock(&(philo->right_fork.flock));
		pthread_mutex_unlock(&(philo->left_fork->flock));
		return (0);
	}
	print_log(philo, FORK);
	if (check_me_tummy(philo))
	{
		pthread_mutex_unlock(&(philo->right_fork.flock));
		pthread_mutex_unlock(&(philo->left_fork->flock));
		return (0);
	}
	print_log(philo, EATING);
	ft_msleep(philo->time->to_eat);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(philo->right_fork.flock));
	pthread_mutex_unlock(&(philo->left_fork->flock));
	(philo->times_eaten)++;
	return (1);
}

int	looking2eat(t_philo *philo)
{
	if (isphilo_even(philo))
		return (even_version(philo));
	return (odd_version(philo));
}
