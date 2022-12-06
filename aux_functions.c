/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:20:15 by afonso            #+#    #+#             */
/*   Updated: 2022/12/06 15:29:14 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	are_argsdigits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

//retorna o numero de args + 1 (da funcao em si)
int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

unsigned long	get_time(void)
{
	struct timeval	timebase;

	gettimeofday(&timebase, NULL);
	return ((timebase.tv_sec * 1000) + (timebase.tv_usec / 1000));
}

void	ft_msleep(t_philo *philo, unsigned long microseconds)
{
	unsigned long	end_time;
	unsigned long	initial_time;

	initial_time = get_time();
	end_time = microseconds + initial_time;
	while (get_time() < end_time)
	{
		if (check_me_tummy(philo))
			return ;
		if (get_time() - initial_time >= microseconds)
			break ;
		usleep(1000);
	}
	return ;
}

int	print_log(t_philo *philo, int action)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&(philo->data->print));
	timestamp = get_time() - philo->time->start;
	if (check_me_tummy(philo))
	{
		pthread_mutex_unlock(&(philo->data->print));
		return (0);
	}
	printf("%lu %d ", timestamp, philo->id);
	if (action == EATING)
		printf("is eating\n");
	else if (action == FORK)
		printf("has taken a fork\n");
	else if (action == ASLEEP)
		printf("is sleeping\n");
	else if (action == THINKING)
		printf("is thinking\n");
	pthread_mutex_unlock(&(philo->data->print));
	return (1);
}
