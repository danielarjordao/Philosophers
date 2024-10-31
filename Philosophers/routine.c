/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:58:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/31 17:07:07 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("%d has taken a fork\n", philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("%d has taken a fork\n", philo->id);
		printf("%d is eating\n", philo->id);
		usleep(1000 * philo->data->time_to_eat);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		printf("%d is sleeping\n", philo->id);
		usleep(1000 * philo->data->time_to_sleep);
		printf("%d is thinking\n", philo->id);
	}
	else
	{
		usleep(100);
		pthread_mutex_lock(philo->r_fork);
		printf("%d has taken a fork\n", philo->id);
		pthread_mutex_lock(philo->l_fork);
		printf("%d has taken a fork\n", philo->id);
		printf("%d is eating\n", philo->id);
		usleep(1000 * philo->data->time_to_eat);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		printf("%d is sleeping\n", philo->id);
		usleep(1000 * philo->data->time_to_sleep);
		printf("%d is thinking\n", philo->id);
	}
	return (NULL);
}
