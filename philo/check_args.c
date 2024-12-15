/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:45:16 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/02 16:46:07 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(t_data *data)
{
	int	i;

	i = 0;
	if (data->num_philosophers <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0	|| data->time_to_sleep <= 0
		|| data->num_times_to_eat < -1)
	{
		if (data->num_philosophers <= 0)
			printf("Wrong argument: number_of_philosophers\n");
		if (data->time_to_die <= 0)
			printf("Wrong argument: time_to_die\n");
		if (data->time_to_eat <= 0)
			printf("Wrong argument: time_to_eat\n");
		if (data->time_to_sleep <= 0)
			printf("Wrong argument: time_to_sleep\n");
		if (data->num_times_to_eat < -1)
			printf("Wrong argument: number_of_times_each_philosopher_must_eat\n");
		i = 1;
	}
	return (i);
}
