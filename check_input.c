/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:40:48 by afonso            #+#    #+#             */
/*   Updated: 2022/11/28 13:16:35 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	checkif_integers(long int *array, int numof_nums)
{
	long int	max;
	long int	min;

	max = INT_MAX;
	min = INT_MIN;
	if (!array)
		return (0);
	while (numof_nums)
	{
		numof_nums--;
		if (array[numof_nums] > max || array[numof_nums] < min)
			return (0);
	}
	return (1);
}

static long int	*fill_numarray(char **args, long int *arg_array)
{
	int	index;
	int	array_size;

	index = 1;
	array_size = count_args(args);
	arg_array = (long int *)malloc(array_size * sizeof(long int));
	while (index < array_size)
	{
		arg_array[index - 1] = ft_atol(args[index]);
		index++;
	}
	return (arg_array);
}

int	check_input(int argc, char **argv, long int	**arg_array)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (!are_argsdigits(argv))
		return (0);
	*arg_array = fill_numarray(argv, *arg_array);
	if (!checkif_integers(*arg_array, count_args(argv) - 1))
	{
		free(*arg_array);
		*arg_array = 0;
		return (0);
	}
	return (1);
}
