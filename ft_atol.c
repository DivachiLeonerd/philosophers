/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:05:15 by afonso            #+#    #+#             */
/*   Updated: 2022/11/06 11:20:17 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	word_count(char *s, char c)
// {
// 	int		i;
// 	int		counter;

// 	counter = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			counter++;
// 			i++;
// 			while (s[i] != c && s[i])
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (counter);
// }

int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	count_digit(char *string)
{
	int i;
	int	count;

	count = 0;
	i = 0;
	while (string[i] != ' ' && ft_isdigit(string[i]) && string[i])
	{
		count++;
		i++;
	}
	if (!ft_isdigit(string[i]) && !(string[i] || string[i] != ' '))
		return (-1);
	return (count);
}

long int	ft_pow(int x, int power)
{
	int	i;
	int	num;

	num = 1;
	i = power;
	if (!power)
		return (1);
	while (i)
	{
		num = num * x;
		i--;
	}
	return (num);
}

long int	digitsum(char *number, int	num_ofdigits)
{
	static long int	num;
	static int		i;
	int				start;
	
	start = i;
	if (i == 0)
		num = 0;
	if (num_ofdigits == 0)
		return (0);
	num = num + ((long)(number[i] - 48) * ft_pow(10, num_ofdigits - 1));
	i++;
	if (i < (num_ofdigits + start))
		return (digitsum(number, num_ofdigits - 1));
	if (number[i] == 0)
		i = 0;
	return (num);
}

long int	ft_atol(char *string)
{
	int			i;
	long int	num;

	i = 0;
	num = 0;
	i = count_digit(string);//count until string[index] == ' '
	num = digitsum(string, i);//sum() is recursive and calls itself with i--;
	return (num);
	
}