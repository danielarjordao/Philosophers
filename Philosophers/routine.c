/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:58:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/02 16:58:05 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *data)
{
	t_philo	*philo;
	int		actual_time;

	philo = (t_philo *)data;
	while (1)
	{
		if (philo->id % 2 == 0)
		{
			eat(philo);
			actual_time = get_time() - philo->data->start_time;
			printf("%d %d is sleeping\n", actual_time, philo->id);
			usleep(1000 * philo->data->time_to_sleep);
			actual_time = get_time() - philo->data->start_time;
			printf("%d %d is thinking\n", actual_time, philo->id);
		}
		else
		{
			usleep(100);
			actual_time = get_time() - philo->data->start_time;
			eat(philo);
			actual_time = get_time() - philo->data->start_time;
			printf("%d %d is sleeping\n", actual_time, philo->id);
			usleep(1000 * philo->data->time_to_sleep);
			actual_time = get_time() - philo->data->start_time;
			printf("%d %d is thinking\n", actual_time, philo->id);
		}
	}
	return (NULL);
}
void	eat(t_philo *philo)
{
	int	actual_time;

	check_death(philo);
	pthread_mutex_lock(philo->l_fork);
	actual_time = get_time() - philo->data->start_time;
	printf("%d %d has taken a fork\n", actual_time, philo->id);
	pthread_mutex_lock(philo->r_fork);
	actual_time = get_time() - philo->data->start_time;
	printf("%d %d has taken a fork\n", actual_time, philo->id);
	philo->last_eaten = get_time();
	printf("%d %d is eating\n", actual_time, philo->id);
	usleep(1000 * philo->data->time_to_eat);
	philo->num_times_eaten++;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
