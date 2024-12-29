/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:54:33 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/29 12:18:55 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int	now;
	int	time_after_eat;

	pthread_mutex_lock(&philo->data->monitor);
	now = get_time();
	time_after_eat = now - philo->last_eaten;
	if (time_after_eat > philo->data->time_to_die)
	{
		if (philo->data->is_dead == 0)
		{
			pthread_mutex_lock(&philo->data->print);
			printf("%d %d died\n", now - philo->data->start_time, \
			philo->id);
			pthread_mutex_unlock(&philo->data->print);
			philo->data->is_dead = 1;
		}
		pthread_mutex_unlock(&philo->data->monitor);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->monitor);
	return (0);
}

int	check_satisfaction(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data->monitor);
	if (philo->data->num_times_to_eat != -1 \
	&& philo->num_times_eaten >= philo->data->num_times_to_eat)
	{
		while (i < philo->data->num_philosophers)
		{
			if (philo->data->philo[i].num_times_eaten
			< philo->data->num_times_to_eat)
				break ;
			i++;
		}
		if (i == philo->data->num_philosophers)
		{
			philo->data->is_satisfied = 1;
			pthread_mutex_unlock(&philo->data->monitor);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->data->monitor);
	return (0);
}

void	*monitor_routine(void *data)
{
	int		i;
	t_data	*tmp_data;

	tmp_data = (t_data *)data;
	while (!finish_meal(tmp_data))
	{
		i = 0;
		while (i < tmp_data->num_philosophers)
		{
			if (check_death(&tmp_data->philo[i]))
				return (NULL);
			if (check_satisfaction(&tmp_data->philo[i]))
				return (NULL);
			i++;
		}
		usleep(50);
	}
	return (NULL);
}

int	finish_meal(t_data *data)
{
	pthread_mutex_lock(&data->monitor);
	if (data->is_dead == 1 || data->is_satisfied == 1)
	{
		pthread_mutex_unlock(&data->monitor);
		return (1);
	}
	pthread_mutex_unlock(&data->monitor);
	return (0);
}
