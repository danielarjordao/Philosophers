/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:45:16 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/26 11:16:04 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(t_data *data, int argc)
{
	if (data->num_philosophers <= 0)
		printf("Wrong argument: number_of_philosophers <= 0\n");
	else if (data->time_to_die <= 0)
		printf("Wrong argument: time_to_die <= 0\n");
	else if (data->time_to_eat <= 0)
		printf("Wrong argument: time_to_eat <= 0\n");
	else if (data->time_to_sleep <= 0)
		printf("Wrong argument: time_to_sleep <= 0\n");
	else if (argc == 6 && data->num_times_to_eat <= 0)
		printf("Wrong argument:\
	number_of_times_each_philosopher_must_eat\n");
	else
	{
		if (data->time_to_die < 60)
			printf("Warning: time_to_die < 60\n");
		if (data->time_to_eat < 60)
			printf("Warning: time_to_eat < 60\n");
		if (data->time_to_sleep < 60)
			printf("Warning: time_to_sleep < 60\n");
		return (0);
	}
	return (1);
}
