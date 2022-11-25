/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:40:48 by afonso            #+#    #+#             */
/*   Updated: 2022/11/14 17:00:28 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//returns 1 if input is valid, 0 if invalid

//no args? exit or return

// function that checks number of arguments. Can only be either 4 or 5

// function that checks for arg[1-4]. They are all digits only, no strings like "one". Will use a split if is_digit condition checks out.
	//note: even if one arg is like "123", I can still apply is_digit() to each char of the number 123

// function that checks the *optional* arg (number of times philo need to eat)


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

//only works with arrays containing only one number. e.g: "123" and NOT "123 321"
static long int	*fill_numarray(char **args, long int *arg_array)
{
	int	index;
	int	array_size;

	index = 1;
	array_size = count_args(args);
	printf("array_size:%d\n", array_size);
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
	//from here, everything is atleast a digit.
	*arg_array = fill_numarray(argv, *arg_array);// I gotta free this array after
	if (!checkif_integers(*arg_array, count_args(argv) - 1))
	{
		printf("Checkif errado\n");
		free(*arg_array);
		*arg_array = 0;
		return (0);
	}
	return (1);
}