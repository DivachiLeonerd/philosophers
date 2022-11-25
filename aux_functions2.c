/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:40:36 by afonso            #+#    #+#             */
/*   Updated: 2022/11/23 18:16:18 by afonso           ###   ########.fr       */
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

/*to do list:
	-fazer uma funçao q converta de lu para char[]
	-fazer uma funçao q converta de d para char[]*/