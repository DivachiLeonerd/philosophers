/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:20:15 by afonso            #+#    #+#             */
/*   Updated: 2022/11/24 13:21:24 by afonso           ###   ########.fr       */
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

unsigned long   get_time()
{
    struct timeval timebase;
    unsigned long   time;
	
    gettimeofday(&timebase, NULL);
    time = (timebase.tv_sec * 1000) + (timebase.tv_usec / 1000);
    return (time);
}

void ft_msleep(unsigned long microseconds)
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
	unsigned long timepassed;
	char			*timestamp;
	char			*id;

	pthread_mutex_lock(&(philo->data->print));
	timepassed = get_time() - philo->time->start;
	timestamp = ft_lutoa(timepassed);
	id = ft_itoa(philo->id);
	//printf("%lums:Philosopher %d", timepassed - philo->time->start, philo->id);
	write(1, timestamp, ft_strlen(timestamp));
	write(1, "ms:Philosopher ", 15);
	write(1, id, ft_strlen(id));
	if (action == EATING)
		write(1, " has taken a fork\n", 18);
	else if (action == ASLEEP)
		write(1, " is sleeping\n", 13);
	else if (action == THINKING)
		write(1, " is thinking\n", 13);
	else
		write(1, " died\n", 6);
	free(timestamp);
	free(id);
	pthread_mutex_unlock(&(philo->data->print));
	return ;
}