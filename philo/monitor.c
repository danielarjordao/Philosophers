/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:54:33 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/20 18:11:51 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->monitor);
	if (get_time() - philo->last_eaten > philo->data->time_to_die)
	{
		if (philo->data->is_dead == 0)
		{
			pthread_mutex_lock(&philo->data->print);
			printf("%d %d died\n", get_time() - philo->data->start_time, philo->id);
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
	if (philo->data->num_times_to_eat != -1 && philo->num_times_eaten >= philo->data->num_times_to_eat)
	{
		while (i < philo->data->num_philosophers)
		{
			if (philo->data->philo[i].num_times_eaten < philo->data->num_times_to_eat)
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
	int	i;
	t_data	*tmp_data;

	tmp_data = (t_data *)data;
	while (tmp_data->is_dead == 0 && tmp_data->is_satisfied == 0)
	{
		i = 0;
		while (i < tmp_data->num_philosophers)
		{
			if (check_death(&tmp_data->philo[i]) || check_satisfaction(&tmp_data->philo[i]))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
