/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:26:05 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/10 13:31:50 by abaldelo         ###   ########.fr       */
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
		philos[i].last_meal = get_timestamp_ms();
		philos[i].start_time = get_timestamp_ms();
		i++;
	}
	return (0);
}

static int	init_extra_mutexes(t_config *config)
{
	if (pthread_mutex_init(&config->meal_look, NULL) != 0)
	{
		destroy_mutexes(config->forks, config->number_philos);
		pthread_mutex_destroy(&config->meal_look);
		return (-1);
	}
	if (pthread_mutex_init(&config->dead_look, NULL) != 0)
	{
		destroy_mutexes(config->forks, config->number_philos);
		pthread_mutex_destroy(&config->meal_look);
		pthread_mutex_destroy(&config->dead_look);
		return (-1);
	}
	if (pthread_mutex_init(&config->full_lock, NULL) != 0)
	{
		destroy_mutexes(config->forks, config->number_philos);
		pthread_mutex_destroy(&config->meal_look);
		pthread_mutex_destroy(&config->dead_look);
		pthread_mutex_destroy(&config->full_lock);
		return (-1);
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
	if (init_extra_mutexes(config) != 0)
		return (message(0), -1);
	return (0);
}

int	init_all(t_config *config)
{
	config->is_dead = 0;
	config->full_count = 0;
	if (init_mutexes(config) != 0)
		return (-1);
	if (init_philosophers(config) != 0)
		return (-1);
	return (0);
}
