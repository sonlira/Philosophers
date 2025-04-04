/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:05:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/04 15:46:09 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(&philo->config->dead_look);
	is_dead = philo->config->is_dead;
	pthread_mutex_unlock(&philo->config->dead_look);
	return (is_dead);
}

static void	thinking(t_philo *philo)
{
	t_config	*config;

	config = philo->config;
	if (!check_death(philo))
		printf("%ld Filóso %d está pensando\n", get_timestamp_ms() - config->start_time, philo->id);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		// printf("Filósofo %d: ha tomado el tenedor derecho\n", philo->id);
		pthread_mutex_lock(philo->left_fork);
		// printf("Filósofo %d: ha tomado el tenedor izquierdo\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		// printf("Filósofo %d: ha tomado el tenedor izquierdo\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		// printf("Filósofo %d: ha tomado el tenedor derecho\n", philo->id);
	}
}

static void	eat(t_philo *philo)
{
	t_config	*config;

	config = philo->config;
	pthread_mutex_lock(&config->meal_look);
	philo->last_meal = get_timestamp_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&config->meal_look);
	if (!check_death(philo))
		printf("%ld Filósofo %d: está comiendo\n",get_timestamp_ms() - config->start_time, philo->id);
	// usleep((config->time_to_eat * 1000));
	safe_sleep(philo, config->time_to_eat);
	
}

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	// printf("Filósofo %d: ha soltado los tenedores\n", philo->id);
}

static void	sleeping(t_philo *philo)
{
	t_config *config;

	config = philo->config;
	if (!check_death(philo))
		printf("%ld Filósofo %d: está durmiendo\n",get_timestamp_ms() - philo->config->start_time, philo->id);
	// usleep(philo->config->time_to_sleep * 1000);
	safe_sleep(philo, config->time_to_sleep);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_death(philo))
	{
		// if (check_death(philo))
		// 	return (NULL);
		thinking(philo);
		take_forks(philo);
		// if (check_death(philo))
		// 	return (NULL);
		eat(philo);
		release_forks(philo);
		// if (check_death(philo))
		// 	return (NULL);
		sleeping(philo);
	}
	// printf("Filosofo %d: hola desde routine. \n", philo->id);
	return (NULL);
}
