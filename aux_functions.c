/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:20:15 by afonso            #+#    #+#             */
/*   Updated: 2022/12/05 12:43:28 by afonso           ###   ########.fr       */
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
	unsigned long	time;

	gettimeofday(&timebase, NULL);
	time = (timebase.tv_sec * 1000) + (timebase.tv_usec / 1000);
	return (time);
}

void	ft_msleep(unsigned long microseconds)
{
	unsigned long	current_time;
	unsigned long	initial_time;
	unsigned long	time_slept;

	initial_time = get_time();
	time_slept = 0;
	while (time_slept < microseconds)
	{
		current_time = get_time();
		time_slept = current_time - initial_time;
	}
	return ;
}

void	print_log(t_philo *philo, int action)
{
	unsigned long	timestamp;

	timestamp = get_time() - philo->time->start;
	pthread_mutex_lock(&(philo->data->print));
	printf("%lums:Philosopher %d", timestamp, philo->id);
	if (action == EATING)
	{
		printf(" has taken a fork\n");
		printf("%lums:Philosopher %d", timestamp, philo->id);
		printf(" is eating\n");
	}
	else if (action == FORK)
		printf(" has taken a fork\n");
	else if (action == ASLEEP)
		printf(" is sleeping\n");
	else if (action == THINKING)
		printf(" is thinking\n");
	else
		printf(" died\n");
	pthread_mutex_unlock(&(philo->data->print));
	return ;
}

