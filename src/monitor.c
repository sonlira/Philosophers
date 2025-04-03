/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:51:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/03 19:20:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_config	*config;
	int			i;
	long		time_since_meal;

	config = (t_config *)arg;
	while (1)
	{
		i = 0;
		while (i < config->number_philos)
		{
			pthread_mutex_lock(&config->meal_look);
			time_since_meal = get_timestamp_ms() - config->philos[i].last_meal;
			pthread_mutex_unlock(&config->meal_look);
			if (time_since_meal > config->time_to_die)
			{
				pthread_mutex_lock(&config->dead_look);
				config->is_dead = 1;
				printf("%ld Filosofo %d ha muerto\n", get_timestamp_ms() - config->start_time, config->philos[i].id);
				pthread_mutex_unlock(&config->dead_look);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
