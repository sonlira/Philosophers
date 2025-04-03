/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:05:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/03 14:44:56 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("Filósofo %d: ha tomado el tenedor izquierdo\n", philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("Filósofo %d: ha tomado el tenedor derecho\n", philo->id);
}

static void	eat(t_philo *philo)
{
	t_config	*config;

	config = philo->config;
	pthread_mutex_lock(&config->meal_look);
	philo->last_meal = get_timestamp_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&config->meal_look);
	printf("Filósofo %d: está comiendo\n", philo->id);
	usleep(config->time_to_eat * 1000);
}

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("Filósofo %d: ha soltado los tenedores\n", philo->id);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		// Falta implementar cositas
	}
	// printf("Filosofo %d: hola desde routine. \n", philo->id);
	return (NULL);
}