/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:26:05 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/02 21:12:32 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	message(int code)
{
	if (code == 0)
		write_error("When initializing the mutex");
	else if (code == 1)
		write_error("Null pointers");
}

static int	init_philosophers(t_config *config)
{
	int		i;
	t_philo	*philos;

	if (!config || !config->forks || !config->philos)
		return (message(1), -1);
	i = 0;
	philos = config->philos;
	while (i < config->number_philos)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &config->forks[i];
		philos[i].right_fork = &config->forks[(i + 1) % config->number_philos];
		philos[i].config = config;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = config->start_time;
		i++;
	}
	return (0);
}

static int	init_mutexes(t_config *config)
{
	int	i;


	if (!config || !config->forks)
		return (message(1), -1);
	i = 0;
	while (i < config->number_philos)
	{
		if (pthread_mutex_init(&config->forks[i], NULL) != 0)
		{
			destroy_mutexes(config->forks, i);
			return (message(0), -1);
		}
		i++;
	}
	return (0);
}

int	init_all(t_config *config)
{
	if (init_mutexes(config) != 0)
		return (-1);
	config->start_time = get_timestamp_ms();
	if (init_philosophers(config) != 0)
		return (-1);
	return (0);
}
