/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:40:36 by afonso            #+#    #+#             */
/*   Updated: 2022/11/28 16:51:43 by afonso           ###   ########.fr       */
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
	if (isphilo_even(philo))
	{
		if (philo->right_fork.is_locked == 0 && !(philo->data->is_dead))
		{
			pthread_mutex_lock(&(philo->right_fork.flock));
			philo->right_fork.is_locked = 1;
			print_log(philo, EATING);
			while (philo->left_fork->is_locked == 1)
			{
				check_me_tummy(philo);
				if (philo->state == DEAD || philo->data->is_dead)
				{
					pthread_mutex_unlock(&(philo->right_fork.flock));
					return (0);
				}
			}
			pthread_mutex_lock(&(philo->left_fork->flock));
			philo->left_fork->is_locked = 1;
			print_log(philo, EATING);
			(philo->times_eaten)++;
			return (1);
		}
	}
	return (0);
}

static int	odd_version(t_philo *philo)
{
	if (!isphilo_even(philo))
	{
		if (philo->left_fork->is_locked == 0 && !(philo->data->is_dead))
		{
			pthread_mutex_lock(&(philo->left_fork->flock));
			philo->left_fork->is_locked = 1;
			print_log(philo, EATING);
			while (philo->right_fork.is_locked == 1)
			{
				check_me_tummy(philo);
				if (philo->state == DEAD || philo->data->is_dead)
				{
					pthread_mutex_unlock(&(philo->left_fork->flock));
					return (0);
				}
			}
			pthread_mutex_lock(&(philo->right_fork.flock));
			philo->right_fork.is_locked = 1;
			print_log(philo, EATING);
			(philo->times_eaten)++;
			return (1);
		}
	}
	return (0);
}

int	looking2eat(t_philo *philo)
{
	if (even_version(philo) || odd_version(philo))
		return (1);
	return (0);
}
