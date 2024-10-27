/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:57:37 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/27 17:36:54 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->num_philosophers = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->num_times_to_eat = atoi(argv[5]);
	else
		data->num_times_to_eat = -1;
}

void	init_philo(t_data *data)
{
	int			i;

	data->philo = malloc(sizeof(pthread_t) * data->num_philosophers);
	if (!data->philo)
	{
		printf("Error: Malloc failed\n");
		exit(1);
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_create(&data->philo[i], NULL, philosopher_routine, data);
		i++;
	}
}

