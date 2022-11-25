/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:23:49 by afonso            #+#    #+#             */
/*   Updated: 2022/11/25 11:12:32 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Checks if philo died of starvation. Only updates in-philo stats
static void	check_me_tummy(t_philo *philo)
{
	if ((get_time() - philo->last_meal) >= philo->time->to_die)
		philo->state = DEAD;
	return ;
}

static int	looking2eat(t_philo *philo)
{
		//nota:se o philo n conseguir dar lock no primeiro fork, entao nao tenta dar lock no segundo
		// se conseguir dar lock no primeiro, aí tenta esperar pelo segundo fork
		if (isphilo_even(philo))//philo is even
		{
			if (philo->right_fork.is_locked == 0)
			{
				pthread_mutex_lock(&(philo->right_fork.flock));
				philo->right_fork.is_locked = 1;
				print_log(philo, EATING);
				//tenho de fazer com q ele continue a checkar se morreu antes de entrar no lock
				while (philo->left_fork->is_locked == 1)
				{
					check_me_tummy(philo);
					if (philo->state == DEAD)
						return (0);
				}
				pthread_mutex_lock(&(philo->left_fork->flock));
				philo->left_fork->is_locked = 1;
				print_log(philo, EATING);
				return (1);
			}
		}
		if (!isphilo_even(philo)) //philo is odd
		{
			if (philo->left_fork->is_locked == 0)
			{
				pthread_mutex_lock(&(philo->left_fork->flock));
				philo->left_fork->is_locked = 1;
				print_log(philo, EATING);
				pthread_mutex_lock(&(philo->right_fork.flock));
				philo->right_fork.is_locked = 1;
				print_log(philo, EATING);
				return (1);
			}
		}
	return (0);
}

//have to update with the global variables and tells program if one philo died (ret == 0)
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
		ft_msleep(philo->time->to_eat);
		philo->last_meal = get_time();
		philo->right_fork.is_locked = 0;
		pthread_mutex_unlock(&(philo->right_fork.flock));
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
		check_me_tummy(philo);
		if (philo->data->is_dead == 1)
			return (NULL);
		if (philo->state == DEAD)
		{
			pthread_mutex_lock(&(philo->data->data_lock));
			if (philo->data->is_dead == 0)
				print_log(philo, DEAD);
			philo->data->is_dead = 1;
			pthread_mutex_unlock(&(philo->data->data_lock));
			return (NULL);
		}
			update_philo_state(philo);
	}
	return (NULL);
}