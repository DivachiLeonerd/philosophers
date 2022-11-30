/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:40:36 by afonso            #+#    #+#             */
/*   Updated: 2022/11/30 14:14:42 by afonso           ###   ########.fr       */
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

// static int	even_version(t_philo *philo)
// {
// 	if (isphilo_even(philo))
// 	{
// 		while (!check_me_tummy(philo))
// 		{
// 			pthread_mutex_lock(&(philo->right_fork.flock));
// 			if (philo->right_fork.is_locked == 0)
// 			{
// 				philo->right_fork.is_locked = 1;
// 				pthread_mutex_unlock(&(philo->right_fork.flock));
// 				break ;
// 			}
// 			pthread_mutex_unlock(&(philo->right_fork.flock));
// 		}
// 		if (check_me_tummy(philo))
// 			return (0);
// 		print_log(philo, FORK);
// 		while (!check_me_tummy(philo))
// 		{
// 			pthread_mutex_lock(&(philo->left_fork->flock));
// 			if (philo->left_fork->is_locked == 0)
// 			{
// 				philo->left_fork->is_locked = 1;
// 				pthread_mutex_unlock(&(philo->left_fork->flock));
// 				break ;
// 			}
// 			pthread_mutex_unlock(&(philo->left_fork->flock));
// 		}
// 		if (check_me_tummy(philo))
// 			return (0);
// 		print_log(philo, EATING);
// 		(philo->times_eaten)++;
// 		return (1);
// 	}
// 	return (0);
// }

// static int	odd_version(t_philo *philo)
// {
// 	if (!isphilo_even(philo))
// 	{
// 		while (!check_me_tummy(philo))
// 		{
// 			pthread_mutex_lock(&(philo->left_fork->flock));
// 			if (philo->left_fork->is_locked == 0)
// 			{
// 				philo->left_fork->is_locked = 1;
// 				pthread_mutex_unlock(&(philo->left_fork->flock));
// 				break ;
// 			}
// 			pthread_mutex_unlock(&(philo->left_fork->flock));
// 		}
// 		if (check_me_tummy(philo))
// 			return (0);
// 		print_log(philo, FORK);
// 		while (!check_me_tummy(philo))
// 		{
// 			pthread_mutex_lock(&(philo->right_fork.flock));
// 			if (philo->right_fork.is_locked == 0)
// 			{
// 				philo->right_fork.is_locked = 1;
// 				pthread_mutex_unlock(&(philo->right_fork.flock));
// 				break ;
// 			}
// 			pthread_mutex_unlock(&(philo->right_fork.flock));
// 		}
// 		if (check_me_tummy(philo))
// 			return (0);
// 		print_log(philo, EATING);
// 		(philo->times_eaten)++;
// 		return (1);
// 	}
// 	return (0);
// }

int	looking2eat(t_philo *philo)
{
	while (!check_me_tummy(philo))
	{
		pthread_mutex_lock(&(philo->right_fork.flock));
		if (philo->right_fork.is_locked == 0)
		{
			philo->right_fork.is_locked = 1;
			pthread_mutex_unlock(&(philo->right_fork.flock));
			break ;
		}
		pthread_mutex_unlock(&(philo->right_fork.flock));
	}
	if (check_me_tummy(philo))
		return (0);
	print_log(philo, FORK);
	while (!check_me_tummy(philo))
	{
		pthread_mutex_lock(&(philo->left_fork->flock));
		if (philo->left_fork->is_locked == 0)
		{
			philo->left_fork->is_locked = 1;
			pthread_mutex_unlock(&(philo->left_fork->flock));
			break ;
		}
		pthread_mutex_unlock(&(philo->left_fork->flock));
	}
	if (check_me_tummy(philo))
		return (0);
	print_log(philo, EATING);
	(philo->times_eaten)++;
	return (1);
}

// int	looking2eat(t_philo *philo)
// {
// 	if (even_version(philo) || odd_version(philo))
// 		return (1);
// 	return (0);
// }

void	write_template(char *timestamp, char *id)
{
	write(1, timestamp, ft_strlen(timestamp));
	write(1, " ", 1);
	// write(1, "ms:Philosopher ", 15);
	write(1, id, ft_strlen(id));
}