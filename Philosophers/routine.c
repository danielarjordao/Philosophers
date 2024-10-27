/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:58:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/27 17:55:18 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *data)
{
	t_data	*philo;
	int		i;

	philo = (t_data *)data;
	i = 0;
	while (philo->philo[i])
	{
		printf("philo[%d] is alive\n", i);
		i++;
	}
	return (NULL);
}
