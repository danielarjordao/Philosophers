/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:12 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/20 14:29:52 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		s;
	int		nb;

	i = 0;
	s = 1;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = s * (-1);
		i = i + 1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (nptr[i] - '0');
		i++;
	}
	return (nb * s);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	clean(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{

		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->monitor);
	clean_data(data);
}

void	clean_data(t_data *data)
{
	if (data->fork)
		free(data->fork);
	if (data->philo)
		free(data->philo);
	if (data)
		free(data);
}

int	check_malloc(void *ptr)
{
	if (!ptr)
	{
		printf("Error: malloc\n");
		return (1);
	}
	return (0);
}
