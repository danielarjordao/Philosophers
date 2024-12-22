/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:50:36 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/22 17:30:33 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	pthread_t		philo_thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				last_eaten;
	int				num_times_eaten;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_to_eat;
	int				start_time;
	int				is_dead;
	int				is_satisfied;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	monitor;
	t_philo			*philo;
}	t_data;

//init.c
int		init_data(t_data *data, int argc, char **argv);
void	init_mutex(t_data *data);
void	init_philo(t_data *data);
void	init_threads(t_data *data);

//check_args.c
int		check_args(t_data *data, int argc);

//routine.c
void	philo_alone(t_philo *philo);
void	*philosopher_routine(void *data);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

//routine_utils.c
void	take_forks(t_philo *philo);
void	take_first_fork(t_philo *philo);
void	take_second_fork(t_philo *philo);
void	my_sleep(int time, t_data *data);

//monitor.c
int		check_death(t_philo *philo);
int		check_satisfaction(t_philo *philo);
void	*monitor_routine(void *data);
int		finish_meal(t_data *data);

// utils.c
int		ft_atoi(const char *nptr);
int		get_time(void);
void	clean(t_data *data);
int		check_malloc(void *ptr);
void	join_philo(t_data *data);

#endif
