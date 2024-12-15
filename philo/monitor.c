/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:54:33 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/02 16:54:55 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philo)
{
	if (philo->data->num_times_to_eat != -1)
	{
		if (philo->num_times_eaten >= philo->data->num_times_to_eat)
			return ;
	}
	if (get_time() - philo->last_eaten > philo->data->time_to_die)
	{
		printf("%d %d died\n", get_time() - philo->data->start_time, philo->id);
		exit(1);
	}
}
