/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:58:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/22 18:18:01 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_alone(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[0]);
	printf("%d %d has taken a fork\n", get_time() - data->start_time, 1);
	my_sleep(data->time_to_die, data);
	printf("%d %d died\n", get_time() - data->start_time, 1);
	pthread_mutex_unlock(&data->fork[0]);
	return ;
}

void	*philosopher_routine(void *philo)
{
	t_philo	*tmp_philo;

	tmp_philo = (t_philo *)philo;
	if (tmp_philo->data->num_philosophers == 1)
	{
		philo_alone(tmp_philo);
		return (NULL);
	}
	if (tmp_philo->id % 2 != 0)
		usleep(500);
	while (!finish_meal(tmp_philo->data))
	{
		if (finish_meal(tmp_philo->data))
			return (NULL);
		eating(tmp_philo);
		sleeping(tmp_philo);
		thinking(tmp_philo);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	int	actual_time;

	take_forks(philo);
	if (!finish_meal(philo->data))
	{
		actual_time = get_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->monitor);
		philo->last_eaten = get_time();
		pthread_mutex_unlock(&philo->data->monitor);
		pthread_mutex_lock(&philo->data->print);
		printf("%d %d is eating\n", actual_time, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		my_sleep(philo->data->time_to_eat, philo->data);
		pthread_mutex_lock(&philo->data->monitor);
		philo->num_times_eaten++;
		pthread_mutex_unlock(&philo->data->monitor);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}

void	sleeping(t_philo *philo)
{
	int	actual_time;

	if (!finish_meal(philo->data))
	{
		actual_time = get_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->print);
		printf("%d %d is sleeping\n", actual_time, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		my_sleep(philo->data->time_to_sleep, philo->data);
	}
}

void	thinking(t_philo *philo)
{
	int	actual_time;

	if (!finish_meal(philo->data))
	{
		actual_time = get_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->print);
		printf("%d %d is thinking\n", actual_time, philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
}
