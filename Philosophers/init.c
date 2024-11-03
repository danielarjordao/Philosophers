/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:57:37 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/03 15:59:13 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_times_to_eat = ft_atoi(argv[5]);
	else
		data->num_times_to_eat = -1;
	if (data->num_philosophers <= 0)
		return ;
	data->start_time = get_time();
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	data->philo = malloc(sizeof(t_philo) * data->num_philosophers);
	if (!data->fork || !data->philo)
	{
		if (!data->fork)
			printf("Error: data->fork malloc\n");
		if (!data->philo)
			printf("Error: data->philo malloc\n");
		exit(1);
	}
}
void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			printf("Error: pthread_mutex_init fork[%d]\n", i);
			exit(1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		printf("Error: pthread_mutex_init print\n");
		exit(1);
	}
	if (pthread_mutex_init(&data->death, NULL) != 0)
	{
		printf("Error: pthread_mutex_init death\n");
		exit(1);
	}
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{

		data->philo[i].id = i + 1;
		data->philo[i].l_fork = &data->fork[i];
		data->philo[i].r_fork = &data->fork[(i + 1) % data->num_philosophers];
		data->philo[i].data = data;
		data->philo[i].last_eaten = data->start_time;
		data->philo[i].num_times_eaten = 0;
		i++;
	}
}

void	init_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->num_times_to_eat == 0)
		return ;
	if (data->num_philosophers == 1)
		philo_alone(data);
	while (i < data->num_philosophers)
	{
		if (pthread_create(&data->philo[i].philo_thread, NULL, philosopher_routine, &data->philo[i]) != 0)
		{
			printf("Error: pthread_create\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(data->philo[i].philo_thread, NULL);
		i++;
	}
}
