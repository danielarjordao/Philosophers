/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:07:36 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/20 11:13:26 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	init_philo(t_philosopher *philo, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].num_philosophers = num_philosophers;
		i++;
	}
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*temp_philo;

	temp_philo = (t_philosopher *)arg;
	if (temp_philo)
		printf("Philosopher %d\n", temp_philo->id);
	printf("End of philosopher %d routine\n", temp_philo->id);
	return (NULL);
}

int	init_threads(pthread_t *philosophers, t_philosopher *philo, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		if (pthread_create(&philosophers[i], NULL, philosopher_routine, &philo[i]) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < num_philosophers)
	{
		if (pthread_join(philosophers[i], NULL) != 0)
		{
			printf("Error joining thread\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main()
{
	int	num_philosophers;
	t_philosopher	*philo;
	pthread_t	*philosophers;

	printf("Enter the number of philosophers: ");
	if (scanf("%d", &num_philosophers) != 1 || num_philosophers < 2)
	{
		printf("Invalid input. Please enter a number greater than 1.\n");
		return (1);
	}
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * num_philosophers);
	philosophers = (pthread_t *)malloc(sizeof(pthread_t) * num_philosophers);
	init_philo(philo, num_philosophers);
	if (init_threads(philosophers, philo, num_philosophers) == 1)
	{
		free(philo);
		free(philosophers);
		return (1);
	}
	free(philo);
	free(philosophers);
}






