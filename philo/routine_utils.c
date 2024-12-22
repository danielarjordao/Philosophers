/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:54:06 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/22 17:45:02 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	take_first_fork(philo);
	take_second_fork(philo);
}

void	take_first_fork(t_philo *philo)
{
	int		actual_time;
	t_data	*data;

	data = philo->data;
	if (!finish_meal(data))
	{
		if (philo->id % 2 == 0)
			pthread_mutex_lock(philo->r_fork);
		else
			pthread_mutex_lock(philo->l_fork);
		if (finish_meal(data))
		{
			if (philo->id % 2 == 0)
				pthread_mutex_unlock(philo->r_fork);
			else
				pthread_mutex_unlock(philo->l_fork);
			return ;
		}
		actual_time = get_time() - data->start_time;
		pthread_mutex_lock(&data->print);
		printf("%d %d has taken a fork\n", actual_time, philo->id);
		pthread_mutex_unlock(&data->print);
	}
}

void	take_second_fork(t_philo *philo)
{
	int		actual_time;
	t_data	*data;

	data = philo->data;
	if (!finish_meal(data))
	{
		if (philo->id % 2 == 0)
			pthread_mutex_lock(philo->l_fork);
		else
			pthread_mutex_lock(philo->r_fork);
		if (finish_meal(data))
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			return ;
		}
		actual_time = get_time() - data->start_time;
		pthread_mutex_lock(&data->print);
		printf("%d %d has taken a fork\n", actual_time, philo->id);
		pthread_mutex_unlock(&data->print);
	}
}

void	my_sleep(int time, t_data *data)
{
	int	start;

	start = get_time();
	while (get_time() - start < time && !finish_meal(data))
		usleep(50);
}
