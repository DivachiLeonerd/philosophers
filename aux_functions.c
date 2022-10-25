/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:20:15 by afonso            #+#    #+#             */
/*   Updated: 2022/10/25 21:52:54 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isdigit(char a)
{
	char array[10];
	int	index;

	index = 0;
	memset(array, '0', 10);
	while (index < 10)
	{
		array[index] += index;
		index++; 
	}
}

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
		}
	}
}