/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:02:53 by afonso            #+#    #+#             */
/*   Updated: 2022/11/25 11:03:11 by afonso           ###   ########.fr       */
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

# define ODD 1
# define EVEN 2


/**************struct definitions***************/

typedef struct s_fork
{
	int				is_locked;// This is a measure to check if locking a fork is viable and to save time for each thread.
					//  note: This is mostly important when mutex is locked (is_locked == 1). If it is 0 then philo will have to use pthread_mutex_lock()
	unsigned long	last_time_used;
	pthread_mutex_t flock;
}t_fork;

typedef struct s_data
{
	int				num_of_philo;
	unsigned int	num_of_meals;
	int 			is_dead;
	int 			how_many_finished;
	int				reference;
	pthread_mutex_t data_lock;
	pthread_mutex_t print;
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
	int					times_eaten;//for the purposes of ending the simulation
	unsigned long		last_meal;//how long has philo gone without eating
	int					state;//as in: eating, sleeping, thinking
	t_fork				right_fork;//fork of n philo
	t_fork				*left_fork;//fork of the n+1 philo
	t_data				*data;//point to data struct with times to eat...
	t_time				*time;
	struct timeval		*timebase;
}t_philo;

/**************function definitions***************/

long int		digitsum(char *number, int	num_ofdigits);
void			checkif_number(char **argv, int *ret_address, int i, int *j);
int				is_integer(void *x);
long int		ft_atol(char *string);
char			*ft_substr(char  *s, unsigned int start, size_t len);
size_t			ft_strlen(char *str);
char			**ft_split(char *s, char c);
int				count_args(char **args);
int				ft_isdigit(char c);
int				how_many_char(char *s, char c, int wordnum);
int				check_input(int argc, char **argv, long int	**arg_array);
int				are_argsdigits(char **argv);
t_philo			*load_philos(t_data *data, t_time *time);
pthread_t		*load_pthreads(t_philo *philo_array, int numof_philo);
void			free_philos(long *args_array);
void			initialize_datastruct(t_data *data, long *arg_array, int argc);
void			initialize_timestruct(t_time *time, long *arg_array);
void			*routine(void *philo);
unsigned long   get_time();
void			print_log(t_philo *philo, int action);
void			free_assets(t_philo *philo_array, long int *arg_array, pthread_t *pthreads);
void			ft_msleep(unsigned long microseconds);
void			threads_join(pthread_t *thread_array, t_data *data);
int				isphilo_even(t_philo *philo);
void			sort_eaters(t_philo *philo);
char			*ft_lutoa(unsigned long n);
char			*ft_itoa(int n);
#endif
