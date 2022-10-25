/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:40:48 by afonso            #+#    #+#             */
/*   Updated: 2022/10/25 21:18:29 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns 1 if input is valid, 0 if invalid

//no args? exit or return

// function that checks number of arguments. Can only be either 4 or 5

// function that checks for arg[1-4]. They are all digits only, no strings like "one". Will use a split if is_digit condition checks out.
	//note: even if one arg is like "123", I can still apply is_digit() to each char of the number 123

// function that checks the *optional* arg (number of times philo need to eat)

int	check_input(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	
	
}