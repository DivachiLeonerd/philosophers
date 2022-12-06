/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:22 by atereso-          #+#    #+#             */
/*   Updated: 2022/12/06 18:29:41 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_philo *philo)
{
	if (philo->data->num_of_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		ft_msleep(philo, philo->time->to_die);
		printf("%u 1 died\n", philo->time->to_die);
		return (1);
	}
	return (0);
}
