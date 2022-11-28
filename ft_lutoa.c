/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:24:44 by afonso            #+#    #+#             */
/*   Updated: 2022/11/28 12:58:30 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo.h"

static	char	*alloc_string(unsigned long n);
static	char	*reverse_string(char *string);

char	*ft_lutoa(unsigned long n)
{
	char				ch;
	int					i;
	char				*string;
	unsigned long		aux;

	aux = n;
	i = 0;
	string = alloc_string(aux);
	if (!string)
		return (NULL);
	if (aux == 0)
		string[i++] = '0';
	while (aux != 0)
	{
		ch = aux % 10 + 48;
		string[i] = ch;
		aux = aux / 10;
		i++;
	}
	string = reverse_string(string);
	return (string);
}

static char	*reverse_string(char *string)
{
	char	tmp;
	int		strlen;
	int		i;
	int		end;
	int		begin;

	i = 0;
	begin = 0;
	strlen = ft_strlen(string);
	end = strlen - 1;
	while (i < (strlen / 2))
	{
		tmp = string[begin];
		string[begin] = string[end];
		string[end] = tmp;
		i++;
		begin++;
		end--;
	}
	return (string);
}

static	char	*alloc_string(unsigned long n)
{
	unsigned int	power;
	char			*string;

	power = 0;
	if (n == 0)
		power++;
	while (n > 0)
	{
		n = n / 10;
		power++;
	}
	string = malloc((power + 1) * sizeof(char));
	memset(string, 0, power + 1);
	if (!string)
		return (NULL);
	return (string);
}
