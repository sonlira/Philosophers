/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/06 16:34:45 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_threads(t_config *config)
{
	int		i;
	int		rsul;
	t_philo	*philo;

	i = 0;
	philo = config->philos;
	while (i < config->number_philos)
	{
		rsul = pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
		if (rsul != 0)
			return (write_error("When creating the threads"), -1);
		i++;
	}
	if (pthread_create(&config->monitor, NULL, monitor, config) != 0)
		return (write_error("When creating the threads"), -1);
	return (0);
}

static int	join_threads(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->number_philos)
	{
		if (pthread_join(config->philos[i].thread, NULL) != 0)
			return (write_error("By joining the threads"), -1);
		i++;
	}
	if (pthread_join(config->monitor, NULL) != 0)
		return (write_error("By joining the threads"), -1);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		philos[MAX_PHILOS];
	t_mtx		forks[MAX_PHILOS];
	t_config	config;

	config.philos = philos;
	config.forks = forks;
	if (parse_args(ac, av, &config) != 0)
		return (1);
	if (init_all(&config) != 0)
		return (1);
	if (start_threads(&config) != 0)
		return (1);
	if (join_threads(&config) != 0)
		return (1);
	destroy_mutexes(config.forks, config.number_philos);
	pthread_mutex_destroy(&config.meal_look);
	pthread_mutex_destroy(&config.dead_look);
	pthread_mutex_destroy(&config.full_lock);
	return (0);
}
