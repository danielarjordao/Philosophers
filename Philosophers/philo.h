/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:50:36 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/02 16:56:05 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo {
	int	id;
	pthread_t	philo_thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int	last_eaten;
	int	num_times_eaten;
	t_data	*data;
} t_philo;

typedef struct s_data {
	int num_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_times_to_eat;
	int	start_time;
	int	end_time;
	pthread_mutex_t	*fork;
	t_philo *philo;
} t_data;

//init.c
void	init_data(t_data *data, int argc, char **argv);
void	init_fork(t_data *data);
void	init_philo(t_data *data);
void	init_threads(t_data *data);

//check_args.c
int	check_args(t_data *data);

//routine.c
void	*philosopher_routine(void *data);
void	eat(t_philo *philo);

//monitor.c
void	check_death(t_philo *philo);

// utils.c
void	clean(t_data *data);
int	get_time(void);
int	check_args(t_data *data);

#endif
