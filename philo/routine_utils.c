/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:54:06 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/21 18:10:42 by dramos-j         ###   ########.fr       */
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
	int	actual_time;

	if (philo->data->is_dead == 0 && philo->data->is_satisfied == 0)
	{
		if (philo->id % 2 == 0)
			pthread_mutex_lock(philo->r_fork);
		else
			pthread_mutex_lock(philo->l_fork);
		if (finish_meal(philo))
			return ;
		actual_time = get_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->print);
		printf("%d %d has taken a fork\n", actual_time, philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void	take_second_fork(t_philo *philo)
{
	int	actual_time;

	if (philo->data->is_dead == 0 && philo->data->is_satisfied == 0)
	{
		if (philo->id % 2 == 0)
			pthread_mutex_lock(philo->l_fork);
		else
			pthread_mutex_lock(philo->r_fork);
		if (finish_meal(philo))
			return ;
		actual_time = get_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->print);
		printf("%d %d has taken a fork\n", actual_time, philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
}
