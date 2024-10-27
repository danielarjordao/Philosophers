/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:50:36 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/27 17:52:17 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_data {
	int num_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_times_to_eat;
	pthread_t *philo;
} t_data;

//init.c
void	init_data(t_data *data, int argc, char **argv);
void	init_philo(t_data *data);

//routine.c
void	*philosopher_routine(void *data);

// utils.c

#endif
