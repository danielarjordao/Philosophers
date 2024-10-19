/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:07:36 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/19 17:44:49 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	init_mutex(pthread_mutex_t *forks, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philo(t_philosopher *philo, int num_philosophers, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		philo[i].id = i;
		philo[i].num_philosophers = num_philosophers;
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % num_philosophers];
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	*philosopher_routine(void *arg)
{
	t_philosopher *temp_philo;
	int	i;

	temp_philo = (t_philosopher *)arg;
	i = 0;
	while (i < temp_philo->num_philosophers)
	{
		printf("Philosopher %d is thinking\n", temp_philo->id);
		pthread_mutex_lock(temp_philo->left_fork);
		pthread_mutex_lock(temp_philo->right_fork);
		printf("Philosopher %d is eating\n", temp_philo->id);
		pthread_mutex_unlock(temp_philo->left_fork);
		pthread_mutex_unlock(temp_philo->right_fork);
		printf("Philosopher %d is sleeping\n", temp_philo->id);
	}
	return (NULL);
}

void	init_threads(pthread_t *philosophers, t_philosopher *philo, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_create(&philosophers[i], NULL, philosopher_routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < num_philosophers)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}
}

void	destroy_mutex(pthread_mutex_t *forks, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	main()
{
	int	num_philosophers;
	t_philosopher	*philo;
	pthread_t	*philosophers;
	pthread_mutex_t	*forks;

	printf("Enter the number of philosophers: ");
	if (scanf("%d", &num_philosophers) != 1 || num_philosophers < 2)
	{
		printf("Invalid input. Please enter a number greater than 1.\n");
		return (1);
	}
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * num_philosophers);
	philosophers = (pthread_t *)malloc(sizeof(pthread_t) * num_philosophers);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_philosophers);
	init_mutex(forks, num_philosophers);
	init_philo(philo, num_philosophers, forks);
	init_threads(philosophers, philo, num_philosophers);
	destroy_mutex(forks, num_philosophers);
}






