/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:51:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/04 15:57:38 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_config	*config;
	int			i;
	long		now;
	long		time_since_meal;

	config = (t_config *)arg;
	while (1)
	{
		i = 0;
		while (i < config->number_philos)
		{
			now = get_timestamp_ms();
			pthread_mutex_lock(&config->meal_look);
			time_since_meal = now - config->philos[i].last_meal;
			pthread_mutex_unlock(&config->meal_look);
			if (time_since_meal > config->time_to_die)
			{
				pthread_mutex_lock(&config->dead_look);
				config->is_dead = 1;
				pthread_mutex_unlock(&config->dead_look);
				printf("%ld Filosofo %d ha muertoOOOOOOOOOOOOOOOOOOOOOOOOOOo\n", now - config->start_time, config->philos[i].id);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
