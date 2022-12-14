/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:02:53 by afonso            #+#    #+#             */
/*   Updated: 2022/12/06 18:28:22 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

# define EATING 0
# define ASLEEP 1
# define THINKING 2
# define DEAD 3
# define FORK 4

# define ODD 1
# define EVEN 2
/**************struct definitions***************/
typedef struct s_fork
{
	int				is_locked;
	pthread_mutex_t	flock;
}t_fork;

typedef struct s_data
{
	unsigned int	num_of_philo;
	unsigned long	num_of_meals;
	int				is_dead;
	pthread_mutex_t	data_lock;
	pthread_mutex_t	print;
}t_data;

typedef struct s_time
{
	unsigned long	start;
	unsigned int	to_sleep;
	unsigned int	to_eat;
	unsigned int	to_die;
}t_time;

typedef struct s_philo
{
	int					id;
	unsigned long		times_eaten;
	unsigned long		last_meal;
	int					state;
	t_fork				right_fork;
	t_fork				*left_fork;
	t_data				*data;
	t_time				*time;
	struct timeval		*timebase;
}t_philo;

/**************function definitions***************/

long int		digitsum(char *number, int num_ofdigits);
long int		ft_atol(char *string);
size_t			ft_strlen(char *str);
int				count_args(char **args);
int				ft_isdigit(char c);
int				check_input(int argc, char **argv, long int	**arg_array);
int				are_argsdigits(char **argv);
t_philo			*load_philos(t_data *data, t_time *time);
pthread_t		*load_pthreads(t_philo *philo_array, int numof_philo);
void			free_philos(long *args_array);
void			initialize_datastruct(t_data *data, long *arg_array, int argc);
void			initialize_timestruct(t_time *time, long *arg_array);
void			*routine(void *philo);
unsigned long	get_time(void);
int				print_log(t_philo *philo, int action);
void			free_assets(t_philo *philo_array, long int *arg_array,
					pthread_t *pthreads);
void			ft_msleep(t_philo *philo, unsigned long microseconds);
void			threads_join(pthread_t *thread_array, t_data *data);
int				isphilo_even(t_philo *philo);
char			*ft_lutoa(unsigned long n);
char			*ft_itoa(int n);
int				looking2eat(t_philo *philo);
int				check_me_tummy(t_philo *philo);
void			write_template(char *timestamp, char *id);
void			*routine2(void *philo);
int				one_philo(t_philo *philo);
#endif
