/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:05:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/10 13:06:19 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thinking(t_philo *philo)
{
	t_config	*config;

	config = philo->config;
	if (!check_death(philo))
		printf("%ld %d is thinking\n"\
			, get_timestamp_ms() - philo->start_time, philo->id);
}

static void	take_forks(t_philo *philo)
{
	t_config	*config;

	config = philo->config;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		if (!check_death(philo))
			printf("%ld %d has taken a fork\n"\
			, get_timestamp_ms() - philo->start_time, philo->id);
		pthread_mutex_lock(philo->left_fork);
		if (!check_death(philo))
			printf("%ld %d has taken a fork\n"\
			, get_timestamp_ms() - philo->start_time, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (!check_death(philo))
			printf("%ld %d has taken a fork\n"\
			, get_timestamp_ms() - philo->start_time, philo->id);
		pthread_mutex_lock(philo->right_fork);
		if (!check_death(philo))
			printf("%ld %d has taken a fork\n"\
			, get_timestamp_ms() - philo->start_time, philo->id);
	}
}

static void	eat(t_philo *philo)
{
	t_config	*config;

	config = philo->config;
	pthread_mutex_lock(&config->meal_look);
	philo->last_meal = get_timestamp_ms();
	philo->meals_eaten++;
	if (config->must_eat != -1 && philo->meals_eaten == config->must_eat)
	{
		pthread_mutex_lock(&config->full_lock);
		config->full_count++;
		pthread_mutex_unlock(&config->full_lock);
	}
	pthread_mutex_unlock(&config->meal_look);
	if (!check_death(philo))
		printf("%ld %d is eating\n"\
			, get_timestamp_ms() - philo->start_time, philo->id);
	safe_sleep(philo, config->time_to_eat);
}

static void	sleeping(t_philo *philo)
{
	t_config	*config;

	config = philo->config;
	if (!check_death(philo))
		printf("%ld %d is sleeping\n"\
			, get_timestamp_ms() - philo->start_time, philo->id);
	safe_sleep(philo, config->time_to_sleep);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->config->number_philos == 1)
	{
		printf("%ld %d has taken a fork\n"\
			, get_timestamp_ms() - philo->start_time, philo->id);
		return (NULL);
	}
	while (!check_death(philo))
	{
		thinking(philo);
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		sleeping(philo);
	}
	return (NULL);
}
